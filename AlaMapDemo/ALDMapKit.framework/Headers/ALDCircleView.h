//
//  ALDCircleView.h
//  ALDMapKit
//
//  Created by Wengys on 15/2/9.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <MapKit/MapKit.h>

/// 圆形遮盖物视图
@interface ALDCircleView : MKCircleView
{
    UIImageView *imageView;
}

/**
 *按照地图等级重绘Overlay
 *@param level 地图等级
 */
- (void)drawOverlayByMapLevel:(NSInteger)level;

@end
