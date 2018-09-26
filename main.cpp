#include <iostream>
#include <gtest/gtest.h>

#include "lazy_singleton.h"
#include "simple_factory.h"
#include "factory.h"
#include "abstract_factory.h"
#include "builder.h"
#include "prototype.h"


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
    EXPECT_NE(fru, (simple_fruit *) NULL);
    fru->get_fruit();

    simple_fruit *fru_bad = fac->create("bad");
    EXPECT_EQ(fru_bad, (simple_fruit *) NULL);

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

TEST(factory, abstract_factory)
{
    abstract_fruit *abs_fruit = NULL;
    abstract_factory *abs_fac = NULL;

    abs_fac = new south_factory();
    abs_fruit = abs_fac->create_apple();
    EXPECT_STREQ(abs_fruit->say_name().c_str(), "south_apple");
    delete abs_fruit;
    delete abs_fac;

    abs_fac = new north_factory();
    abs_fruit = abs_fac->create_banana();
    EXPECT_STREQ(abs_fruit->say_name().c_str(), "north_banana");
    delete abs_fruit;
    delete abs_fac;

}

TEST(builder, test_validity)
{
    director dirt;
    builder *bud = NULL;
    house *hos = NULL;
    bud = new villa_builder();
    dirt.set_builder(bud);
    dirt.construct();
    hos = bud->get_house();
    EXPECT_STREQ(hos->getDoor().c_str(), "villa_door");
    delete hos;
    delete bud;

    bud = new flat_builder();
    dirt.set_builder(bud);
    dirt.construct();
    hos = bud->get_house();
    EXPECT_STREQ(hos->getDoor().c_str(), "flat_door");
    delete hos;
    delete bud;
}

TEST(prototype, test_validity)
{
    java_programmer java_p1("jason", 30);
    java_p1.set_resume("I am java");
    person *p2 = java_p1.clone();  //对象具有自我复制功能 注意深拷贝和浅拷贝问题
    p2->print_out();

    delete p2;
}

int main(int argc, char *argv[])
{
    printf("Design-Patterns!\n");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
