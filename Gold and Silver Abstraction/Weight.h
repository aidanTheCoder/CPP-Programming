#pragma once
class Weight {
    double weightInPounds;
    static constexpr double OZ_PER_LB = 16;
    static constexpr double GRAMS_PER_OZ = 28.35;
public:
    Weight() : weightInPounds(0.0) {}
    void setInPounds(double pounds) { weightInPounds = pounds; }
    double getInGrams();
};

