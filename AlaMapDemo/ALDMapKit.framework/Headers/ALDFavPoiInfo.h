//
//  ALDFavPoiInfo.h
//  ALDMapKit
//
//  Created by apple on 15/8/27.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/**收藏点种别
 *FAVPOI_INFOTYPE_NORMAL    - 普通收藏点
 *FAVPOI_INFOTYPE_HOME      - 家
 *FAVPOI_INFOTYPE_COMPANY   - 公司
 */
typedef enum {
    FAVPOI_INFOTYPE_NORMAL = 0,     ///<普通收藏点
    FAVPOI_INFOTYPE_HOME,           ///<家
    FAVPOI_INFOTYPE_COMPANY         ///<公司
}FAVPOI_INFOTYPE_ENUM;

///收藏点信息类
@interface ALDFavPoiInfo : NSObject

///收藏点种别
@property (nonatomic, assign) NSInteger favType;
///poi名称（添加或更新时，必须有）
@property (nonatomic, strong) NSString* poiName;
///poi坐标（添加或更新时，必须有）
@property (nonatomic, assign) CLLocationCoordinate2D pt;
///poi地址
@property (nonatomic, strong) NSString* address;
///城市名称
@property (nonatomic, strong) NSString* cityName;
///添加或最后修改时间戳
@property (nonatomic, assign) NSUInteger timeStamp;
///字典对象，plist保存用
@property (nonatomic, strong) NSDictionary *dictionaryData;

/**
 *初始化收藏点对象
 *@param type       收藏点种别
 *@param coor       poi坐标
 *@param dictionary 地址数据对象
 */
- (id)initWithType:(NSInteger)type coordinate:(CLLocationCoordinate2D)coor param:(NSDictionary *)param;

@end
