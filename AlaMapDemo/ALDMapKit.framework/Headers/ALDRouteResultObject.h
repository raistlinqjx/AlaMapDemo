//
//  ALDRouteResultObject.h
//  ALDMapKit
//
//  Created by Wengys on 15/3/14.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

///节点信息对象，包括id、名称、经纬度坐标
@interface ALDPointInfo : NSObject

///节点序号
@property (nonatomic, assign)NSInteger uid;
///节点名称
@property (nonatomic, retain)NSString* name;
///节点坐标
@property (nonatomic) CLLocationCoordinate2D pt;

@end

///Step的详细描述对象
@interface ALDStepInfo : NSObject

///路段序号
@property (nonatomic, assign)NSInteger sid;
///途经点或者道路，或者收费站信息描述
@property (nonatomic, retain)NSString* desc;
///子线路的文字描述，其中为Step数组，每个Step元素代表一段具体路段的描述。成员类型为ALDStepInfo
@property (nonatomic, retain)NSArray *subSteps;
///路段个数
@property (nonatomic, assign)NSInteger count;
///单个路段的距离，单位米。
@property (nonatomic, assign)NSInteger distance;
///单个路段经纬度点。成员类型为ALDRoutePoint
@property (nonatomic, retain)NSArray *segments;

@end

///路线搜索结果
@interface ALDRouteResultObject : NSObject

///起点信息对象
@property (nonatomic, readonly, retain)ALDPointInfo *Start;
///终点信息对象
@property (nonatomic, readonly, retain)ALDPointInfo *End;
///整个路线的距离，单位米。
@property (nonatomic, readonly, assign)NSInteger Distance;
///总用时，单位是中文的。例如：31分钟
@property (nonatomic, readonly, retain)NSString *Time;
///打车票价，只有在存在当前城市打车价格数据且距离小于200公里时，才返回该字段。
@property (nonatomic, readonly, assign)NSInteger Price;
///包含起终点在内的途经点信息，如果没有途经点，则只返回起终点。成员类型为ALDPointInfo
@property (nonatomic, readonly, retain)NSArray *Waypoints;
///Steps是对线路的文字描述，其中为Step数组，每个Step元素代表一段具体路段的描述。成员类型为ALDStepInfo
@property (nonatomic, readonly, retain)NSArray *Steps;
///Routes是对线路的地图（坐标序列）描述。成员类型为ALDRoutePoint
@property (nonatomic, readonly, retain)NSArray *Routes;

/**
 *初始化路径搜索结果对象
 *@param dictionary 数据对象
 */
- (id)initWithDictionary:(NSDictionary *)dictionary;

/**
 *初始化路径搜索结果对象
 *@param response 数据对象
 */
- (id)initWithMapResponse:(MKDirectionsResponse *)response;

@end
