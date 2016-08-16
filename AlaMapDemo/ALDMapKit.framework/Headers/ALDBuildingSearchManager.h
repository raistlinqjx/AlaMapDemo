//
//  ALDBuildingSearchManager.h
//  ALDMapKit
//
//  Created by tvMac on 15/11/8.
//  Copyright © 2015年 edushi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "ALDSearchCommonHeader.h"

///建筑点数据对象
@interface ALDBuildingPointObject : NSObject

///地址
@property (nonatomic, readonly, retain)NSString *address;
///名称
@property (nonatomic, readonly, retain)NSString *name;
///经纬度
@property (nonatomic, readonly, assign)CLLocationCoordinate2D coordinate;
///建筑编号
@property (nonatomic, readonly, assign)NSInteger bid;
///描述
@property (nonatomic, readonly, retain)NSString *descript;
///数据类型
@property (nonatomic, readonly, assign)NSInteger type;

/**
 *初始化建筑点数据对象
 *@param dictionary 数据对象
 */
- (id)initWithDictionary:(NSDictionary *)dictionary;

@end

///建筑相关检索服务
@interface ALDBuildingSearchManager : NSObject

/**
 *建筑轮廓关键字查询
 *@param city 城市名称,未指定可以设nil
 *@param keyword 查询关键字
 *@param center 中心点坐标
 *@param type 数据类型
 *@param block 回调
 */
+ (void)searchBuildingInCity:(NSString *)city
                     keyword:(NSString *)keyword
                      center:(CLLocationCoordinate2D)center
                        type:(int)type
                       Block:(void (^)(NSString *key, NSArray *placeList))block;

@end
