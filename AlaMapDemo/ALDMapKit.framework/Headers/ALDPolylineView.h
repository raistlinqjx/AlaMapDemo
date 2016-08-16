//
//  ALDPolylineView.h
//  ALDMapKit
//
//  Created by Wengys on 15/2/11.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <MapKit/MapKit.h>

/// 折线遮盖物视图
@interface ALDPolylineView : MKPolylineView
{
    UIImageView *imageView;
}

/// 是否为虚线样式
@property BOOL lineDash;

/// 是否为弧线样式
@property BOOL lineArc;

/**
 *按照地图等级重绘Overlay
 *@param level 地图等级
 */
- (void)drawOverlayByMapLevel:(NSInteger)level;

/**
 *重绘Overlay
 */
- (void)redrawOverlay;

@end
