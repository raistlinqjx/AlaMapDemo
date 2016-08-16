//
//  ALDBusResultObject.h
//  ALDMapKit
//
//  Created by apple on 15/5/26.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

///公交线路查询结果
@interface ALDBusLineResultObject : NSObject

///线路ID编号
@property (nonatomic, readonly, assign)NSInteger lineId;
///线路名称
@property (nonatomic, readonly, retain)NSString* name;
///对向线路名称
@property (nonatomic, readonly, retain)NSString* oppName;
///站点类型，1 公交，2 地铁，3 磁悬浮，4 轮渡，5 索道，6 BRT
@property (nonatomic, readonly, assign)NSInteger type;
///是否为环线，0 否，1 是
@property (nonatomic, readonly, assign)BOOL isCircle;
///线路经纬度坐标数组。成员类型为ALDRoutePoint
@property (nonatomic, readonly, retain)NSArray *points;
///对向线路经纬度坐标数组。成员类型为ALDRoutePoint
@property (nonatomic, readonly, retain)NSArray *oppPoints;
///上行线路站点串。成员类型为NSString
@property (nonatomic, readonly, retain)NSArray *upStopIds;
///下行线路站点串。成员类型为NSString
@property (nonatomic, readonly, retain)NSArray *downStopIds;
///行政区编号
@property (nonatomic, readonly, assign)NSInteger districtId;
///线路号
@property (nonatomic, readonly, retain)NSString* line;

/**
 *初始化公交线路查询结果对象
 *@param dictionary 数据对象
 */
- (id)initWithDictionary:(NSDictionary *)dictionary;

@end

///公交站点查询结果
@interface ALDBusStopResultObject : NSObject

///站点ID编号
@property (nonatomic, readonly, assign)NSInteger stopId;
///站点名称
@property (nonatomic, readonly, retain)NSString* name;
///站点经纬度坐标
@property (nonatomic, readonly, assign)CLLocationCoordinate2D point;
///对向站点经纬度坐标
@property (nonatomic, readonly, assign)CLLocationCoordinate2D oppPoint;
///站点类型，0 公交车站，1 轨道交通站，2 BRT专用站，9其他
@property (nonatomic, readonly, assign)NSInteger type;
///邻居站点ID编号串。成员类型为NSString
@property (nonatomic, readonly, retain)NSArray *neighborIds;
///此站点经过的线路编号串。成员类型为NSString
@property (nonatomic, readonly, retain)NSArray *viaLineIds;
///行政区编号
@property (nonatomic, readonly, assign)NSInteger districtId;

/**
 *初始化公交站点查询结果对象
 *@param dictionary 数据对象
 */
- (id)initWithDictionary:(NSDictionary *)dictionary;

@end
