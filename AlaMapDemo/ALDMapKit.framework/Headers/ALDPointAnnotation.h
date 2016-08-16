//
//  ALDPointAnnotation.h
//  ALDMapKit
//
//  Created by Wengys on 15/1/27.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

/**标注类型
 *ANNOTATION_TYPE_PIN  - 大头针
 *ANNOTATION_TYPE_PIC  - 图片
 *ANNOTATION_TYPE_CLU  - 组
 *ANNOTATION_TYPE_ANM  - 动画
 *ANNOTATION_TYPE_HAL  - 标签
 */
typedef enum {
    ANNOTATION_TYPE_PIN = 0,    ///<大头针
    ANNOTATION_TYPE_PIC,        ///<图片
    ANNOTATION_TYPE_CLU,        ///<组
    ANNOTATION_TYPE_ANM,        ///<动画
    ANNOTATION_TYPE_HAL         ///<标签
}ANNOTATION_TYPE_ENUM;

///表示一个点的annotation
@interface ALDPointAnnotation : NSObject <MKAnnotation>

///该点的坐标
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;
///标注类型
@property (nonatomic, assign) ANNOTATION_TYPE_ENUM type;
///annotation标题
@property (nonatomic, copy) NSString *title;
///annotation副标题
@property (nonatomic, copy) NSString *subtitle;
///标注索引
@property (nonatomic,assign) NSInteger index;
///头像图片(同步)
@property (nonatomic,retain) UIImage* image;
///头像图片(异步下载)
@property (nonatomic,retain) NSURL* imageURL;
///背景图片
@property (nonatomic,retain) UIImage* background;
///锚点偏移位置(距离背景图片中心点的偏差值)
@property (nonatomic,assign) CGPoint offset;
///聚合半径，像素单位
@property (nonatomic, assign) double radius;
///标柱数组
@property (nonatomic, retain) NSArray* annotations;
///是否响应点击事件,默认YES
@property (nonatomic, assign) BOOL tapEnable;
///是否显示动态闪光效果,默认NO
@property (nonatomic, assign) BOOL flashEnable;

/**
 *初始化标注
 *@param coord 经纬度坐标值
 *@return ALDPointAnnotation对象
 */
- (id)initWithLocation:(CLLocationCoordinate2D)coord;

/**
 *初始化标注
 *@param type 标注类型
 *@return ALDPointAnnotation对象
 */
- (id)initWithType:(ANNOTATION_TYPE_ENUM)type;

/**
 *初始化标注
 *@param title 标题
 *@param latitude 纬度
 *@param longitude 经度
 *@return ALDPointAnnotation对象
 */
- (id)initWithTitle:(NSString *)title latitue:(float)latitude longitude:(float)longitude;

@end
