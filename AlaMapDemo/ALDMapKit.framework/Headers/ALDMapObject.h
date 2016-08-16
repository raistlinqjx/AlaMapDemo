//
//  ALDMapObject.h
//  ALDMapKit
//
//  Created by Wengys on 15/2/7.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <Foundation/Foundation.h>

///地图数据对象
@interface ALDMapObject : NSObject

///地图显示等级(默认11～18)
@property (nonatomic, readonly, assign)NSInteger level;
///瓦块行号
@property (nonatomic, readonly, assign)NSInteger px;
///瓦块列号
@property (nonatomic, readonly, assign)NSInteger py;
///经度
@property (nonatomic, readonly, assign)double longitude;
///纬度
@property (nonatomic, readonly, assign)double latitude;
///地图区域版本号
@property (nonatomic, readonly, assign)NSInteger version;
///地图区域编号
@property (nonatomic, readonly, retain)NSString *areaID;

/**
 *初始化地图数据对象
 *@param dictionary 数据对象
 */
- (id)initWithDictionary:(NSDictionary *)dictionary;

@end
