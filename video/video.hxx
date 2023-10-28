#ifndef JB_VIDEO_H
#define JB_VIDEO_H
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "nlohmann/detail/macro_scope.hpp"
// 视频播放状态
enum class JbVideoPlayStatus : unsigned char {
    // 未开始
    NotStarted = 0,
    // 正在播放
    Playing = 1,
    // 暂停
    Paused = 2,
    // 停止
    Stopped = 3,
    // 播放完成
    Completed = 4
};

// 视频类型
enum class JbVideoType : unsigned char {
    // 普通视频
    Normal = 0,
    // 直播
    Live = 1,
    // 回放
    Replay = 2
};

// 视频的种类,比如文化体育等等
enum class JbVideoKind : unsigned short {};
// 视频
class JbVideo {
  public:
    // 所属的用户，如果为空则属于所有的用户
    std::vector<std::string> user_names;
    // 视频的播放状态,只要有一个人在观看就认为在播放
    JbVideoPlayStatus play_status;
    // 视频正在观看的人数
    unsigned int watching_count;
    // 视频的文件的名或者文件的Url
    std::string file_name;
    // 视频类型
    JbVideoType type;
    // 视频的种类
    JbVideoKind kind;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(JbVideo, user_names, play_status, watching_count, file_name, type, kind)
};

// 获得一个用户感兴趣的视频(从属于所有用户的视频或者属于的用户包含此用户的视频中获取一个)
class GetInterestVideoRequest {
  public:
    // 用户名
    std::string user_name;
    // 视频的类型
    JbVideoType video_type;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(GetInterestVideoRequest, user_name, video_type)
};

// 获得一个用户感兴趣的视频返回
class GetInterestVideoResponse {
  public:
    // 视频资源名
    std::string video_name;
    // 视频的rtsp地址
    std::string video_url;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(GetInterestVideoResponse, video_name, video_url)
};

// 批量获得感兴趣的视频
class BatchGetInterestVideosRequest {
  public:
    // 用户名
    std::vector<std::string> user_names;
    // 视频类型
    JbVideoType video_type;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(BatchGetInterestVideosRequest, user_names, video_type)
};

// 批量获得感兴趣的视频返回
class BatchGetInterestVideosResponse {
  public:
    class InterestVideosSummary {
      public:
        // 用户资源名
        std::string user_name;
        // 视频资源名
        std::vector<std::string> video_names;
        // 视频的rtsp地址
        std::vector<std::string> video_urls;
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(InterestVideosSummary, user_name, video_names, video_urls)
    };
    InterestVideosSummary summary;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(BatchGetInterestVideosResponse, summary)
};

// 取消一个用户对于拉流的需求
class CancelUserStreamRequest {
  public:
    // 用户资源名
    std::string user_name;
    // 视频资源名
    std::string video_name;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(CancelUserStreamRequest, user_name, video_name)
};

// 删除一个视频
class DeleteVideoRequest {
  public:
    // 视频资源名
    std::string video_name;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(DeleteVideoRequest, video_name)
};

// 取消一个用户对某一个视频的权限
class CancelUserVideoRightRequest {
  public:
    // 用户资源名
    std::string user_name;
    // 视频资源名
    std::string video_name;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(CancelUserVideoRightRequest, user_name, video_name)
};

// 获得一个视频请求
class GetVideoRequest {
  public:
    // 视频资源名
    std::string video_name;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(GetVideoRequest, video_name)
};

// 批量获取视频
class BatchGetVideosRequest {
  public:
    // 视频资源名
    std::vector<std::string> video_names;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(BatchGetVideosRequest, video_names)
};

// 批量获取视频响应
class BatchGetVideosResponse {
  public:
    // 视频资源名
    std::vector<JbVideo> videos;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(BatchGetVideosResponse, videos)
};

// 列出视频
class ListVideoRequest {
  public:
    //用户资源名
    std::string user_name;
    int page_size;
    int page_number;
    // 排序方式
    std::string sort_by;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(ListVideoRequest, user_name, page_size, page_number, sort_by)
};

// 列出视频响应
class ListVideoResponse {
  public:
    // 视频资源名
    std::vector<JbVideo> videos;
    int total_count;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(ListVideoResponse, videos, total_count)
};

#endif