//
//  ALDPoiSearchResultObject.h
//  ALDMapKit
//
//  Created by Wengys on 15/3/9.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

///POI详细信息
@interface ALDPoiDetailInfo : NSObject

///POI地址
@property (nonatomic, retain) NSString* address;
///POI检索分类
@property (nonatomic, retain) NSString* category;
///POI检索子分类
@property (nonatomic, retain) NSString* subcategory;
///POI所在城市
@property (nonatomic, retain) NSString* city;
///POI所在省份
@property (nonatomic, retain) NSString* province;
///POI所在地区
@property (nonatomic, retain) NSString* county;
///POI电话号码
@property (nonatomic, retain) NSString* phone;
///POI简介内容
@property (nonatomic, retain) NSString* poidesc;
///POI行政区编号
@property (nonatomic, assign) NSInteger districtId;
///与中心点的距离，单位为米
@property (nonatomic, assign) NSInteger distance;

@end

///POI搜索结果
@interface ALDPoiSearchResultObject : NSObject

///POI的唯一标识
@property (nonatomic, readonly, retain)NSNumber* uid;
///POI名称
@property (nonatomic, readonly, retain)NSString* name;
///POI坐标
@property (nonatomic, readonly) CLLocationCoordinate2D pt;
///POI详细信息
@property (nonatomic, readonly, retain)ALDPoiDetailInfo* detail;

/**
 *初始化POI搜索结果对象(搜狗数据)
 *@param dictionary 数据对象
 */
- (id)initWithDictionary:(NSDictionary *)dictionary;

/**
 *初始化POI搜索结果对象(立得数据)
 *@param dictionary 数据对象
 */
- (id)initWithDictionaryALD:(NSDictionary *)dictionary;

/**
 *初始化POI搜索结果对象(苹果数据)
 *@param item 数据对象
 */
- (id)initWithMapItems:(MKMapItem *)item;

@end
