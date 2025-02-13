#include "TestStats.h"

#include "Stats.h"

TestStats::TestStats() :
    TestObject(nullptr)
{}

void TestStats::set_up() {
    stats = new Stats();
}

void TestStats::tear_down() {
    delete stats;
}

void TestStats::test_all() {
    qDebug() << "TestStats";
    set_up();
    test_values_after_initialization();
    tear_down();

    set_up();
    test_weapon_skill_gains();
    tear_down();
}

void TestStats::test_values_after_initialization() {

}

void TestStats::test_weapon_skill_gains() {
    const unsigned initial_2h_axe_skill = stats->get_twohand_axe_skill();
    const unsigned initial_2h_mace_skill = stats->get_twohand_mace_skill();
    const unsigned initial_2h_sword_skill = stats->get_twohand_sword_skill();
    const unsigned initial_1h_axe_skill = stats->get_axe_skill();
    const unsigned initial_1h_mace_skill = stats->get_mace_skill();
    const unsigned initial_1h_sword_skill = stats->get_sword_skill();

    stats->increase_twohand_axe_skill(5);
    assert(initial_2h_axe_skill + 5 == stats->get_twohand_axe_skill());
    assert(initial_2h_mace_skill == stats->get_twohand_mace_skill());
    assert(initial_2h_sword_skill == stats->get_twohand_sword_skill());
    assert(initial_1h_axe_skill == stats->get_axe_skill());
    assert(initial_1h_mace_skill == stats->get_mace_skill());
    assert(initial_1h_sword_skill == stats->get_sword_skill());

    stats->decrease_twohand_axe_skill(5);
    assert(initial_2h_axe_skill == stats->get_twohand_axe_skill());
    assert(initial_2h_mace_skill == stats->get_twohand_mace_skill());
    assert(initial_2h_sword_skill == stats->get_twohand_sword_skill());
    assert(initial_1h_axe_skill == stats->get_axe_skill());
    assert(initial_1h_mace_skill == stats->get_mace_skill());
    assert(initial_1h_sword_skill == stats->get_sword_skill());

    stats->increase_twohand_mace_skill(5);
    assert(initial_2h_axe_skill == stats->get_twohand_axe_skill());
    assert(initial_2h_mace_skill + 5 == stats->get_twohand_mace_skill());
    assert(initial_2h_sword_skill == stats->get_twohand_sword_skill());
    assert(initial_1h_axe_skill == stats->get_axe_skill());
    assert(initial_1h_mace_skill == stats->get_mace_skill());
    assert(initial_1h_sword_skill == stats->get_sword_skill());

    stats->decrease_twohand_mace_skill(5);
    assert(initial_2h_axe_skill == stats->get_twohand_axe_skill());
    assert(initial_2h_mace_skill == stats->get_twohand_mace_skill());
    assert(initial_2h_sword_skill == stats->get_twohand_sword_skill());
    assert(initial_1h_axe_skill == stats->get_axe_skill());
    assert(initial_1h_mace_skill == stats->get_mace_skill());
    assert(initial_1h_sword_skill == stats->get_sword_skill());

    stats->increase_twohand_sword_skill(5);
    assert(initial_2h_axe_skill == stats->get_twohand_axe_skill());
    assert(initial_2h_mace_skill == stats->get_twohand_mace_skill());
    assert(initial_2h_sword_skill + 5 == stats->get_twohand_sword_skill());
    assert(initial_1h_axe_skill == stats->get_axe_skill());
    assert(initial_1h_mace_skill == stats->get_mace_skill());
    assert(initial_1h_sword_skill == stats->get_sword_skill());

    stats->decrease_twohand_sword_skill(5);
    assert(initial_2h_axe_skill == stats->get_twohand_axe_skill());
    assert(initial_2h_mace_skill == stats->get_twohand_mace_skill());
    assert(initial_2h_sword_skill == stats->get_twohand_sword_skill());
    assert(initial_1h_axe_skill == stats->get_axe_skill());
    assert(initial_1h_mace_skill == stats->get_mace_skill());
    assert(initial_1h_sword_skill == stats->get_sword_skill());

    stats->increase_axe_skill(5);
    assert(initial_2h_axe_skill == stats->get_twohand_axe_skill());
    assert(initial_2h_mace_skill == stats->get_twohand_mace_skill());
    assert(initial_2h_sword_skill == stats->get_twohand_sword_skill());
    assert(initial_1h_axe_skill + 5 == stats->get_axe_skill());
    assert(initial_1h_mace_skill == stats->get_mace_skill());
    assert(initial_1h_sword_skill == stats->get_sword_skill());

    stats->decrease_axe_skill(5);
    assert(initial_2h_axe_skill == stats->get_twohand_axe_skill());
    assert(initial_2h_mace_skill == stats->get_twohand_mace_skill());
    assert(initial_2h_sword_skill == stats->get_twohand_sword_skill());
    assert(initial_1h_axe_skill == stats->get_axe_skill());
    assert(initial_1h_mace_skill == stats->get_mace_skill());
    assert(initial_1h_sword_skill == stats->get_sword_skill());

    stats->increase_mace_skill(5);
    assert(initial_2h_axe_skill == stats->get_twohand_axe_skill());
    assert(initial_2h_mace_skill == stats->get_twohand_mace_skill());
    assert(initial_2h_sword_skill == stats->get_twohand_sword_skill());
    assert(initial_1h_axe_skill == stats->get_axe_skill());
    assert(initial_1h_mace_skill + 5 == stats->get_mace_skill());
    assert(initial_1h_sword_skill == stats->get_sword_skill());

    stats->decrease_mace_skill(5);
    assert(initial_2h_axe_skill == stats->get_twohand_axe_skill());
    assert(initial_2h_mace_skill == stats->get_twohand_mace_skill());
    assert(initial_2h_sword_skill == stats->get_twohand_sword_skill());
    assert(initial_1h_axe_skill == stats->get_axe_skill());
    assert(initial_1h_mace_skill == stats->get_mace_skill());
    assert(initial_1h_sword_skill == stats->get_sword_skill());

    stats->increase_sword_skill(5);
    assert(initial_2h_axe_skill == stats->get_twohand_axe_skill());
    assert(initial_2h_mace_skill == stats->get_twohand_mace_skill());
    assert(initial_2h_sword_skill == stats->get_twohand_sword_skill());
    assert(initial_1h_axe_skill == stats->get_axe_skill());
    assert(initial_1h_mace_skill == stats->get_mace_skill());
    assert(initial_1h_sword_skill + 5 == stats->get_sword_skill());

    stats->decrease_sword_skill(5);
    assert(initial_2h_axe_skill == stats->get_twohand_axe_skill());
    assert(initial_2h_mace_skill == stats->get_twohand_mace_skill());
    assert(initial_2h_sword_skill == stats->get_twohand_sword_skill());
    assert(initial_1h_axe_skill == stats->get_axe_skill());
    assert(initial_1h_mace_skill == stats->get_mace_skill());
    assert(initial_1h_sword_skill == stats->get_sword_skill());
}
