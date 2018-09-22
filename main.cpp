#include <iostream>
#include <gtest/gtest.h>

#include "lazy_singleton.h"
#include "simple_factory.h"
#include "factory.h"

TEST(singleton, same_object)
{
    EXPECT_EQ(lazy_singleton::get_instance(), lazy_singleton::get_instance());
    lazy_singleton::free_instance();

    EXPECT_EQ(eager_singleton::get_instance(), eager_singleton::get_instance());
    eager_singleton::free_instance();
}

TEST(simple_factory, test_validity)
{
    factory *fac = new factory();

    simple_fruit *fru = fac->create("simple_banana");
    EXPECT_NE(fru, (simple_fruit *)NULL);
    fru->get_fruit();

    simple_fruit *fru_bad = fac->create("bad");
    EXPECT_EQ(fru_bad, (simple_fruit *)NULL);

    delete fru;

    delete fac;
}

TEST(factory, test_validity)
{
    abst_factory *abst_fac = NULL;
    fruit *fru = NULL;

    abst_fac = new banana_factory();
    fru = abst_fac->create();
    EXPECT_STREQ(fru->say_name().c_str(), "banana");
}

int main(int argc, char *argv[])
{
    printf("Design-Patterns!\n");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
