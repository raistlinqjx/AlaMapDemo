//
//  ALDNaviResultObject.h
//  ALDMapKit
//
//  Created by Wengys on 15/5/16.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

///导航步骤对象
@interface ALDNaviStep : NSObject

///步骤起点经纬度
@property (nonatomic, assign)CLLocationCoordinate2D begin;
///步骤终点经纬度
@property (nonatomic, assign)CLLocationCoordinate2D end;
///转向类型
@property (nonatomic, assign)NSInteger turnType;
///道路名称
@property (nonatomic, retain)NSString *name;
///行点数
@property (nonatomic, assign)NSInteger ptNum;
///行点串, 成员类型为ALDRoutePoint
@property (nonatomic, retain)NSArray *polyline;
///行点长度，米
@property (nonatomic, assign)NSInteger length;
///耗时，分钟
@property (nonatomic, assign)NSInteger time;

@end

///公交换乘步骤
@interface ALDTranistNode : NSObject

///经由站点数
@property (nonatomic, assign)NSInteger viaStationNum;
///耗时，分钟
@property (nonatomic, assign)NSInteger time;
///距离，米
@property (nonatomic, assign)NSInteger distance;
///步骤起点经纬度
@property (nonatomic, assign)CLLocationCoordinate2D startPt;
///步骤终点经纬度
@property (nonatomic, assign)CLLocationCoordinate2D endPt;
///起点名称
@property (nonatomic, retain)NSString *sStopName;
///终点名称
@property (nonatomic, retain)NSString *eStopName;
///是否步行
@property (nonatomic, assign)BOOL isWalk;
///步骤类型(标识该路线分段的通行工具类型)
@property (nonatomic, assign)NSInteger type;
///线路名称
@property (nonatomic, retain)NSString *lineName;
///兄弟节点数
@property (nonatomic, assign)NSInteger brotherNodeNum;
///兄弟节点数组(存放某路线分段的其他通行线路信息)
@property (nonatomic, retain)NSArray *brotherNodes;
///行点数
@property (nonatomic, assign)NSInteger ptNum;
///行点串, 成员类型为ALDRoutePoint
@property (nonatomic, retain)NSArray *polyline;

@end

///公交换乘方案
@interface ALDTranistRoute : NSObject

///总距离，米
@property (nonatomic, assign)NSInteger allDistance;
///总耗时，分钟
@property (nonatomic, assign)NSInteger allTime;
///换乘步骤数
@property (nonatomic, assign)NSInteger nodeNum;
///步骤数组, 成员类型为ALDTranistNode
@property (nonatomic, retain)NSArray *nodes;
///导航线路经纬度数组。成员类型为ALDRoutePoint
@property (nonatomic, retain)NSArray *routes;

@end

///导航路线搜索结果
@interface ALDNaviResultObject : NSObject

///总距离，米
@property (nonatomic, readonly, assign)NSInteger distance;
///总耗时，秒
@property (nonatomic, readonly, assign)NSInteger duration;
///打车费用，单位是“分”。
@property (nonatomic, readonly, assign)NSInteger cost;
///红绿灯个数
@property (nonatomic, readonly, assign)NSInteger trafficLights;
///导航步骤数组。成员类型为ALDNaviStep
@property (nonatomic, readonly, retain)NSArray *steps;
///导航线路经纬度数组。成员类型为ALDRoutePoint
@property (nonatomic, readonly, retain)NSArray *routes;
///公交换乘方案数组。成员类型为ALDTranistRoute
@property (nonatomic, readonly, retain)NSArray *tranist;

/**
 *初始化导航路线搜索结果对象
 *@param dictionary 数据对象
 */
- (id)initWithDictionary:(NSDictionary *)dictionary;

/**
 *初始化导航路线搜索结果对象
 *@param array 数据数组
 */
- (id)initWithArray:(NSArray *)array;

@end
