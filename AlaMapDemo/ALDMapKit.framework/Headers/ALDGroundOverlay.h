//
//  ALDGroundOverlay.h
//  ALDMapKit
//
//  Created by Wengys on 15/2/11.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <MapKit/MapKit.h>

///表示一个经纬度区域
typedef struct {
    CLLocationCoordinate2D northEast;	///< 东北角点经纬度坐标
    CLLocationCoordinate2D southWest;	///< 西南角点经纬度坐标
} ALDCoordinateBounds;

///图片遮盖物对象
@interface ALDGroundOverlay : MKMultiPoint <MKOverlay>

/// 返回区域中心坐标
@property (nonatomic, readonly) CLLocationCoordinate2D centerCoor;

/// 返回区域外接矩形
@property (nonatomic, readonly) MKMapRect myBoundingMapRect;

/// 两种绘制GroundOverlay的方式之一：绘制的位置地理坐标，与anchor配对使用
@property (nonatomic,assign) CLLocationCoordinate2D pt;

/// 用位置绘制时图片的锚点，图片左上角为(0.0f,0.0f),向右向下为正
/// 使用groundOverlayWithPosition初始化时生效
@property (nonatomic,assign) CGPoint anchor;

/// 两种绘制GroundOverlay的方式之二：绘制的地理区域范围，图片在此区域内合理缩放
@property (nonatomic,assign) ALDCoordinateBounds bound;

/// 绘制图片列表(图片个数＝1:静态图片,图片个数>1:动画)
@property(nonatomic, strong) NSArray *icons;

/// 为图象的一个循环。 默认值是图象的编号* 1/30秒(即30 fps)
@property(nonatomic) NSTimeInterval animationDuration;

/// 图片纹理透明度,最终透明度 = 纹理透明度 * alpha,取值范围为[0.0f, 1.0f]，默认为1.0f
@property(nonatomic) GLfloat alpha;

/**
 *根据指定经纬度坐标生成一个groundOverlay
 *@param position 指定的经纬度坐标
 *@param zoomLevel 不损失精度绘制原始图片的地图等级
 *@param anchor 绘制图片的锚点
 *@param icon   绘制使用的图片
 *@return 新生成的groundOverlay对象
 */
+ (ALDGroundOverlay *)groundOverlayWithPosition:(CLLocationCoordinate2D)position
                                      zoomLevel:(CGFloat)zoomLevel
                                         anchor:(CGPoint)anchor
                                          icons:(NSArray*)icons;

/**
 *根据指定区域生成一个groundOverlay
 *@param bounds 指定的经纬度区域
 *@param icon 绘制使用的图片
 *@return 新生成的groundOverlay对象
 */
+ (ALDGroundOverlay *)groundOverlayWithBounds:(ALDCoordinateBounds)bounds
                                        icons:(NSArray*)icons;

@end
