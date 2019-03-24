#include "HeroicStrike.h"

#include "CharacterStats.h"
#include "CombatRoll.h"
#include "DeepWounds.h"
#include "Flurry.h"
#include "MainhandAttackWarrior.h"
#include "NoEffectBuff.h"
#include "OverpowerBuff.h"
#include "Warrior.h"
#include "WarriorSpells.h"

HeroicStrike::HeroicStrike(Character* pchar) :
    Spell("Heroic Strike", "Assets/ability/Ability_rogue_ambush.png", pchar, RestrictedByGcd::No, 0, ResourceType::Rage, 15),
    TalentRequirer(QVector<TalentRequirerInfo*>{new TalentRequirerInfo("Improved Heroic Strike", 3, DisabledAtZero::No)}),
    warr(dynamic_cast<Warrior*>(pchar)),
    hs_buff(new NoEffectBuff(pchar, BuffDuration::PERMANENT))
{
    hs_buff->enable_buff();
    spell_ranks = {11, 21, 32, 44, 58, 80, 111, 138, 157};
    spell_rank = 8;
    additional_dmg = spell_ranks[spell_rank];

    talent_ranks = {15, 14, 13, 12};
}

HeroicStrike::~HeroicStrike() {
    delete hs_buff;
}

bool HeroicStrike::is_queued() const {
    return hs_buff->is_active();
}

void HeroicStrike::cancel() {
    hs_buff->cancel_buff();
}

void HeroicStrike::calculate_damage() {
    hs_buff->cancel_buff();
    warr->get_spells()->get_mh_attack()->complete_swing();

    const int result = roll->get_melee_ability_result(warr->get_mh_wpn_skill(), pchar->get_stats()->get_mh_crit_chance());

    if (result == PhysicalAttackResult::MISS) {
        increment_miss();
        warr->lose_rage(static_cast<unsigned>(resource_cost));
        return;
    }
    if (result == PhysicalAttackResult::DODGE) {
        increment_dodge();
        warr->get_overpower_buff()->apply_buff();
        warr->lose_rage(static_cast<unsigned>(round(resource_cost * 0.25)));
        return;
    }
    if (result == PhysicalAttackResult::PARRY) {
        increment_parry();
        warr->lose_rage(static_cast<unsigned>(round(resource_cost * 0.25)));
        return;
    }

    double damage_dealt = damage_after_modifiers(warr->get_random_non_normalized_mh_dmg() + additional_dmg);

    if (result == PhysicalAttackResult::CRITICAL) {
        warr->melee_mh_yellow_critical_effect();
        add_crit_dmg(static_cast<int>(round(damage_dealt * warr->get_stats()->get_melee_ability_crit_dmg_mod())), resource_cost, 0);
    }
    else if (result == PhysicalAttackResult::HIT) {
        warr->melee_mh_yellow_hit_effect();
        add_hit_dmg(static_cast<int>(round(damage_dealt)), resource_cost, 0);
    }

    warr->lose_rage(static_cast<unsigned>(resource_cost));
}

void HeroicStrike::spell_effect() {
    hs_buff->apply_buff();
}

void HeroicStrike::increase_talent_rank_effect(const QString&, const int curr) {
    resource_cost = talent_ranks[curr];
}

void HeroicStrike::decrease_talent_rank_effect(const QString&, const int curr) {
    resource_cost = talent_ranks[curr];
}
