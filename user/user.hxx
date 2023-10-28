#ifndef JB_USER_H
#define JB_USER_H
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "nlohmann/detail/macro_scope.hpp"

enum class KinShip { Father, Mother, Son, Daughter, Brother, Sister, Uncle, Aunt, Cousin, Grandfather, Grandmother, Grandson, Granddaughter, GreatUncle, GreatAunt, GreatCousin, Unknown };

struct KinShipAndID {
    KinShip kinShip;
    std::string id;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(KinShipAndID, kinShip, id);
};

// 书籍
class JbUser {
  public:
    // 资源名
    std::string name;
    struct IdentityInfo {
        // 显示名称
        std::string display_name;
        // 身份证号
        std::string id_card;
        // 亲缘关系
        std::vector<KinShipAndID> kin_ship_and_id;
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(IdentityInfo, display_name, id_card, kin_ship_and_id)
    } identityInfo;

    struct PropertyInfo {
        // 性别
        std::string gender;
        // 年龄
        int age;
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(PropertyInfo, gender, age)
    } PropertyInfo;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(JbUser, name, identityInfo, PropertyInfo)
};
#endif