#ifndef JB_USER_H
#define JB_USER_H
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "nlohmann/detail/macro_scope.hpp"

enum class KinShip : unsigned char {
    Father = 1,
    Mother,
    Son,
    Daughter,
    Brother,
    Sister,
    Uncle,
    Aunt,
    Cousin,
    Grandfather,
    Grandmother,
    Grandson,
    Granddaughter,
    GreatUncle,
    GreatAunt,
    GreatCousin,
    Unknown
};

struct KinShipAndID {
    KinShip kin_ship;
    std::string id;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(KinShipAndID, kin_ship, id)
};

enum RegisterStatus : unsigned char {
    // 未登录
    LogOut = 1,
    LogIn = 2
};

// 书籍
class JbUser {
  public:
    // 资源名
    std::string name;

    // 身份信息
    struct IdentityInfo {
        // 显示名称
        std::string display_name;
        // 身份证号
        std::string id_card;
        // 亲缘关系
        std::vector<KinShipAndID> kin_ship_and_id;
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(IdentityInfo, display_name, id_card, kin_ship_and_id)
    } identity_info;

    // 资产信息
    struct PropertyInfo {
        // 性别
        std::string gender;
        // 年龄
        int age;
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(PropertyInfo, gender, age)
    } property_info;

    // 登录状态
    RegisterStatus register_status;

    // 用户登录状态
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(JbUser, name, identity_info, property_info)
};

// 获取用户请求
class JbGetUserRequest {
  public:
    // 资源名
    std::string name;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(JbGetUserRequest, name)
};

// 批量获取用户请求
class JbBatchGetUserRequest {
  public:
    // 资源名
    std::vector<std::string> names;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(JbBatchGetUserRequest, names)
};

// 批量获取用户返回
class JbBatchGetUserResponse {
  public:
    // 用户
    std::vector<JbUser> users;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(JbBatchGetUserResponse, users)
};

// 列出用户请求
class JbListUserRequest {
  public:
    // 排序方式
    std::string sort_by;
    std::string page_size;
    std::string page_number;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(JbListUserRequest, sort_by)
};

// 列出用户返回
class JbListUserResponse {
  public:
    // 用户
    std::vector<JbUser> users;
    // 总数量
    int total_count;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(JbListUserResponse, users)
};

// 改变用户登录状态请求
class JbChangeUserRegisterStatusRequest {
  public:
    // 资源名
    std::string name;
    // 状态
    RegisterStatus status;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(JbChangeUserRegisterStatusRequest, name, status)
};

// 注销账号,既销户(可以通过一定方式找回)
class JbLogOffUserRequest {
  public:
    // 资源名
    std::string name;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(JbLogOffUserRequest, name)
};

// 删除账号，彻底删除这个账号的所有相关信息，无法找回
class JbDeleteUserRequest {
  public:
    // 资源名
    std::string name;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(JbDeleteUserRequest, name)
};
#endif