//
//  ALDFavPoiManager.h
//  ALDMapKit
//
//  Created by apple on 15/8/27.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ALDFavPoiInfo.h"

///收藏点管理类
@interface ALDFavPoiManager : NSObject

/**
 * 添加一个poi点
 * @param favPoiInfo 点信息
 * @return 成功返回YES，失败返回NO
 */
- (BOOL)addFavPoi:(ALDFavPoiInfo*) favPoiInfo;

/**
 * 获取所有收藏点信息
 * @return 点信息数组,成员类型ALDFavPoiInfo
 */
- (NSArray *)getAllFavPois;

/**
 * 删除一个收藏点
 * @param favPoiInfo 点信息
 * @return 成功返回YES，失败返回NO
 */
- (BOOL)deleteFavPoi:(ALDFavPoiInfo*) favPoiInfo;

/**
 * 清空所有收藏点
 */
- (void)clearAllFavPois;

@end
