//
//  ALDPolygonView.h
//  ALDMapKit
//
//  Created by Wengys on 15/2/10.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <MapKit/MapKit.h>

/// 多边形遮盖物视图
@interface ALDPolygonView : MKPolygonView
{
    UIImageView *imageView;
}

/// 是否为虚线样式
@property BOOL lineDash;

/**
 *按照地图等级重绘Overlay
 *@param level 地图等级
 */
- (void)drawOverlayByMapLevel:(NSInteger)level;

@end
