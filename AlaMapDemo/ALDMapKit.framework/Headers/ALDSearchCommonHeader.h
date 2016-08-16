//
//  ALDSearchCommonHeader.h
//  ALDMapKit
//
//  Created by Wengys on 15/5/15.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#ifndef ALDMapKit_ALDSearchCommonHeader_h
#define ALDMapKit_ALDSearchCommonHeader_h

#pragma mark - 共通

///屏幕检索参数信息
typedef struct {
    double topLeftX;        ///< 屏幕左上角横坐标
    double topLeftY;        ///< 屏幕左上角纵坐标
    double bottomRightX;    ///< 屏幕右下角横坐标
    double bottomRightY;    ///< 屏幕右下角纵坐标
} ALDAreaSearchBounds;

/**POI分类
 *
 *POI_CLASS_ALL             - 全分类
 *POI_CLASS_DINING          - 餐饮
 *POI_CLASS_TRADE           - 零售业
 *POI_CLASS_CAR             - 汽车
 *POI_CLASS_HOTEL           - 住宿
 *POI_CLASS_ENTERTAINMENT   - 娱乐
 *POI_CLASS_PUBLIC          - 公共设施
 *POI_CLASS_TRANSPORTATION  - 交通
 *POI_CLASS_CULTURAL        - 文化、媒体
 *POI_CLASS_OTHER           - 其他
 *POI_CLASS_NATURAL         - 自然地物
 */
typedef enum {
    POI_CLASS_ALL = 0,          ///<全分类
    POI_CLASS_DINING,           ///<餐饮
    POI_CLASS_TRADE,            ///<零售业
    POI_CLASS_CAR,              ///<汽车
    POI_CLASS_HOTEL,            ///<住宿
    POI_CLASS_ENTERTAINMENT,    ///<娱乐
    POI_CLASS_PUBLIC,           ///<公共设施
    POI_CLASS_TRANSPORTATION,   ///<交通
    POI_CLASS_CULTURAL,         ///<文化、媒体
    POI_CLASS_OTHER,            ///<其他
    POI_CLASS_NATURAL           ///<自然地物
} POI_CLASS_ENUM;

/**导航类型
 *NAVI_TYPE_DRIVING     - 驾车
 *NAVI_TYPE_TRANIST     - 公交
 *NAVI_TYPE_RIDING      - 骑行
 *NAVI_TYPE_WALKING     - 步行
 *NAVI_TYPE_TRACING     - 轨迹
 */
typedef enum {
    NAVI_TYPE_DRIVING = 0,  ///<驾车
    NAVI_TYPE_TRANIST,      ///<公交
    NAVI_TYPE_RIDING,       ///<骑行
    NAVI_TYPE_WALKING,      ///<步行
    NAVI_TYPE_TRACING       ///<轨迹
}NAVI_TYPE_ENUM;

#pragma mark - 导航

/**换乘模式
 *TRANSIT_MODE_TRANSFER     - 少换乘(公交)
 *TRANSIT_MODE_TIME         - 较快捷(公交)
 *TRANSIT_MODE_WALK         - 少步行(公交)
 */
typedef enum {
    TRANSIT_MODE_TRANSFER = 1,  ///<少换乘(公交)
    TRANSIT_MODE_TIME,          ///<较快捷(公交)
    TRANSIT_MODE_WALK           ///<少步行(公交)
}TRANSIT_MODE_ENUM;

/**导航模式
 *DRIVING_MODE_TIME         - 推荐路线(驾车/步行)
 *DRIVING_MODE_DIST         - 最短路程(驾车/步行)
 *DRIVING_MODE_FREE         - 少走高速(驾车/步行)
 */
typedef enum {
    DRIVING_MODE_TIME = 0,  ///<推荐路线(驾车/步行)
    DRIVING_MODE_DIST,      ///<最短路程(驾车/步行)
    DRIVING_MODE_FREE       ///<少走高速(驾车/步行)
}DRIVING_MODE_ENUM;

/**车导转向类型
 *TURNTYPE_FORWARD          - 直行
 *TURNTYPE_LEFT             - 左转
 *TURNTYPE_RIGHT            - 右转
 *TURNTYPE_BACKWARD         - 调头
 *TURNTYPE_LEFT_FORWARD     - 左前方
 *TURNTYPE_RIGHT_FORWARD    - 右前方
 *TURNTYPE_LEFT_BACKWARD    - 左后转
 *TURNTYPE_RIGHT_BACKWARD   - 右后转
 */
typedef enum {
    TURNTYPE_FORWARD = 11,      ///<直行
    TURNTYPE_LEFT,              ///<左转
    TURNTYPE_RIGHT,             ///<右转
    TURNTYPE_BACKWARD,          ///<调头
    TURNTYPE_LEFT_FORWARD = 21, ///<左前方
    TURNTYPE_RIGHT_FORWARD,     ///<右前方
    TURNTYPE_LEFT_BACKWARD,     ///<左后转
    TURNTYPE_RIGHT_BACKWARD     ///<右后转
}TURNTYPE_ENUM;

#pragma mark - 公交

/**通行工具(站线)类型
 *TRANIST_LINE_WALK     - 步行
 *TRANIST_LINE_BUS      - 公交
 *TRANIST_LINE_SUBWAY   - 地铁
 *TRANIST_LINE_MAGLEV   - 磁悬浮
 *TRANIST_LINE_FERRY    - 轮渡
 *TRANIST_LINE_CABLE    - 索道
 *TRANIST_LINE_BRT      - BRT
 */
typedef enum {
    TRANIST_LINE_WALK = 0,  ///<步行
    TRANIST_LINE_BUS,       ///<公交
    TRANIST_LINE_SUBWAY,    ///<地铁
    TRANIST_LINE_MAGLEV,    ///<磁悬浮
    TRANIST_LINE_FERRY,     ///<轮渡
    TRANIST_LINE_CABLE,     ///<索道
    TRANIST_LINE_BRT        ///<BRT
}TRANIST_LINE_ENUM;

/**站点类型
 *TRANIST_STOP_BUS      - 公交车站
 *TRANIST_STOP_RAILWAY  - 轨道交通站
 *TRANIST_STOP_BRT      - BRT专用站
 *TRANIST_STOP_OTHER    - 其他
 */
typedef enum {
    TRANIST_STOP_BUS = 0,  ///<公交车站
    TRANIST_STOP_RAILWAY,  ///<轨道交通站
    TRANIST_STOP_BRT,      ///<BRT专用站
    TRANIST_STOP_OTHER = 9 ///<其他
}TRANIST_STOP_ENUM;

#pragma mark - 矢量数据

///矢量数据类型
enum VectorType_e {
    VectorType_Point    = 1 << 0,   ///<点
    VectorType_Line     = 1 << 1,   ///<线
    VectorType_Shape    = 1 << 2,   ///<面
};

///兴趣点类型
enum Vector_PoiType_e
{
    Vector_PoiType_All              = -1,       ///<所有兴趣点
    Vector_PoiType_GasStation       = 1 << 0,	///<加油站 0
    Vector_PoiType_Business         = 1 << 1,	///<商业大厦 1
    Vector_PoiType_Restaurant       = 1 << 2,	///<餐饮 2
    Vector_PoiType_Compre           = 1 << 3,	///<综合 3
    Vector_PoiType_Government       = 1 << 4,	///<政府单位 4
    Vector_PoiType_Hotel            = 1 << 5,	///<宾馆旅馆 5
    Vector_PoiType_Bank             = 1 << 6,	///<银行 6
    Vector_PoiType_Capital          = 1 << 7,	///<省会 7
    Vector_PoiType_City             = 1 << 8,	///<地级市 8
    Vector_PoiType_County           = 1 << 9,   ///<县 9
    Vector_PoiType_Town             = 1 << 10,	///<乡 10
    Vector_PoiType_Village          = 1 << 11,	///<村 11
    Vector_PoiType_HiRail           = 1 << 12,  ///<高速相关 12
    Vector_PoiType_StructurePoint   = 1 << 13,	///<建筑物点 13
    Vector_PoiType_Leisure          = 1 << 14,	///<休闲娱乐 14
};

///道路类型
enum Vector_RoadType_e
{
    Vector_RoadType_All        = -1,        ///<所有道路
    Vector_RoadType_Expy       = 1 << 0,    ///<高速 0
    Vector_RoadType_Railway    = 1 << 1,	///<铁路 1
    Vector_RoadType_HiRail     = 1 << 2,	///<高铁 2
    Vector_RoadType_Beltway    = 1 << 3,	///<环城高速 3
    Vector_RoadType_National   = 1 << 4,	///<国道 4
    Vector_RoadType_Provincial = 1 << 5,	///<省道 5
    Vector_RoadType_County     = 1 << 6,	///<县道 6
    Vector_RoadType_City_1     = 1 << 7,	///<市区一级 7
    Vector_RoadType_City_2     = 1 << 8,	///<市区二级 8
    Vector_RoadType_City_Other = 1 << 9,	///<市区杂路 9
    Vector_RoadType_Guide      = 1 << 10,	///<高架引路 10
    Vector_RoadType_Other      = 1 << 11,	///<其它道路 11
    Vector_RoadType_Aux        = 1 << 12,	///<辅道 12
};

///覆盖物类型
enum Vector_OverlayType_e
{
    Vector_OverlayType_All             = -1,        ///<所有覆盖物
    Vector_OverlayType_StructureShape  = 1 << 0,	///<建筑物面 0
    Vector_OverlayType_River           = 1 << 1,	///<河流 1
    Vector_OverlayType_Grassland       = 1 << 2,	///<草地 2
    Vector_OverlayType_Reservoir       = 1 << 3,	///<水库 3
};

///省份
enum Vector_ProvinceType_e
{
    Vector_ProvinceType_All            = -1,        ///<所有省份
    Vector_ProvinceType_AnHui          = 1 << 0,    ///<安徽
    Vector_ProvinceType_BeiJing        = 1 << 1,    ///<北京
    Vector_ProvinceType_ChongQing      = 1 << 2,    ///<重庆
    Vector_ProvinceType_FuJian         = 1 << 3,    ///<福建
    Vector_ProvinceType_GanSu          = 1 << 4,    ///<甘肃
    Vector_ProvinceType_GuangDong      = 1 << 5,    ///<广东
    Vector_ProvinceType_GuangXi        = 1 << 6,    ///<广西
    Vector_ProvinceType_GuiZhou        = 1 << 7,    ///<贵州
    Vector_ProvinceType_HaiNan         = 1 << 8,    ///<海南
    Vector_ProvinceType_HeBei          = 1 << 9,    ///<河北
    Vector_ProvinceType_HeiLongJiang   = 1 << 10,   ///<黑龙江
    Vector_ProvinceType_HeNan          = 1 << 11,   ///<河南
    Vector_ProvinceType_HuBei          = 1 << 12,   ///<湖北
    Vector_ProvinceType_HuNan          = 1 << 13,   ///<湖南
    Vector_ProvinceType_JiangSu        = 1 << 14,   ///<江苏
    Vector_ProvinceType_JiangXi        = 1 << 15,   ///<江西
    Vector_ProvinceType_JiLin          = 1 << 16,   ///<吉林
    Vector_ProvinceType_LiaoNing       = 1 << 17,   ///<辽宁
    Vector_ProvinceType_NeiMengGu      = 1 << 18,   ///<内蒙古
    Vector_ProvinceType_NingXia        = 1 << 19,   ///<宁夏
    Vector_ProvinceType_QinGHai        = 1 << 20,   ///<青海
    Vector_ProvinceType_ShanDong       = 1 << 21,   ///<山东
    Vector_ProvinceType_ShangHai       = 1 << 22,   ///<上海
    Vector_ProvinceType_ShanXi         = 1 << 23,   ///<山西
    Vector_ProvinceType_ShanXiSheng    = 1 << 24,   ///<陕西省
    Vector_ProvinceType_SiChuan        = 1 << 25,   ///<四川
    Vector_ProvinceType_TianJin        = 1 << 26,   ///<天津
    Vector_ProvinceType_XinJiang       = 1 << 27,   ///<新疆
    Vector_ProvinceType_XiZang         = 1 << 28,   ///<西藏
    Vector_ProvinceType_YunNan         = 1 << 29,   ///<云南
    Vector_ProvinceType_ZheJiang       = 1 << 30,   ///<浙江
};

#endif
