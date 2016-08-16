//
//  ALDBusinessSearchManager.h
//  ALDMapKit
//
//  Created by tvMac on 15/11/8.
//  Copyright © 2015年 edushi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

///商家建筑数据信息
@interface ALDBusinessDataObject : NSObject

///建筑id
@property (nonatomic, readonly, assign)NSInteger edifice_id;
///省
@property (nonatomic, readonly, retain)NSString *province;
///市
@property (nonatomic, readonly, retain)NSString *city;
///大厦名称
@property (nonatomic, readonly, retain)NSString *name;
///建筑图片
@property (nonatomic, readonly, retain)NSString *photo;
///描述
@property (nonatomic, readonly, retain)NSString *descript;
///建筑几何。成员类型为ALDRoutePoint
@property (nonatomic, readonly, retain)NSArray *points;
///地址
@property (nonatomic, readonly, retain)NSString *address;

/**
 *初始化商家建筑数据信息对象
 *@param dictionary 数据对象
 */
- (id)initWithDictionary:(NSDictionary *)dictionary;

@end

///商家检索服务
@interface ALDBusinessSearchManager : NSObject

/**
 *获取屏幕范围内建筑数据
 *@param coordinate 经纬度坐标
 *@param block 回调
 */
+ (void)fetchBuildingDataWithLocation:(CLLocationCoordinate2D)center
                                Block:(void (^)(NSArray *buildingList))block;

/**
 *取消建筑数据获取
 */
+ (void)cancelRequestBuildingData;

@end
