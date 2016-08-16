//
//  ALDMapViewDelegate.h
//  ALDMapKit
//
//  Created by apple on 15/8/11.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ALDMapView;

/// MapView的Delegate，mapView通过此类来通知用户对应的事件
@protocol ALDMapViewDelegate <NSObject>
@optional

/**
 *地图初始化完毕时会调用此接口
 *@param mapview 地图View
 */
- (void)mapViewDidFinishLoading:(ALDMapView *)mapView;

/**
 *点击定位按钮开始定位时会调用此接口
 *@param mapview 地图View
 */
- (void)mapViewWillStartLocating:(ALDMapView *)mapView;

/**
 *地图定位完毕时会调用此接口
 *@param coordinate 当前位置GPS
 */
- (void)mapViewDidLocated:(CLLocationCoordinate2D)coordinate;

/**
 *地图定位失败时会调用此接口
 *@param coordinate 前回定位成功的位置GPS
 */
- (void)mapViewDidLocatedFailed:(CLLocationCoordinate2D)coordinate;

/**
 *地图移动开始时会调用此接口
 *@param mapview 地图View
 */
- (void)mapViewWillBeginMoving:(ALDMapView *)mapView;

/**
 *地图移动完毕时会调用此接口
 *@param obj 返回屏幕中心点地图数据对象
 */
- (void)mapViewDidEndMoving:(ALDMapObject *)obj;

/**
 *地图缩放完毕时会调用此接口
 *@param mapview 地图View
 */
- (void)mapViewDidEndZooming:(ALDMapView *)mapView;

/**
 *地图开始缩放时会调用此接口
 *@param mapview 地图View
 */
- (void)mapViewWillStartZooming:(ALDMapView *)mapView;

/**
 *点击代驾列表按钮会回调用此接口
 *@param mapview 地图View
 */
- (void)mapViewDidDriveListBtnClick:(ALDMapView *)mapView;

/**
 *单击地图时会回调此接口
 *@param mapview 地图View
 *@param obj 返回单击处地图数据对象
 */
- (void)mapView:(ALDMapView *)mapView onSingleClick:(ALDMapObject *)obj;

/**
 *双击地图时会回调此接口
 *@param mapview 地图View
 *@param obj 返回双击处地图数据对象
 */
- (void)mapview:(ALDMapView *)mapView onDoubleClick:(ALDMapObject *)obj;

/**
 *长按地图时会回调此接口
 *@param mapview 地图View
 *@param obj 返回长按处地图数据对象
 */
- (void)mapview:(ALDMapView *)mapView onLongClick:(ALDMapObject *)obj;

/**
 *点击高亮建筑时会回调此接口
 *@param mapview 地图View
 *@param buildingName 高亮的建筑名称
 */
- (void)mapViewDidTapBuildingHighlighted:(ALDBusinessDataObject *)buildingData;

/**
 *生成小人位置对应的Callout View
 *@param mapView 地图View
 *@return callout View
 */
- (UIView *)calloutViewForLocation:(ALDMapView *)mapView;

/**
 *生成建筑高亮对应的Callout View
 *@param mapView 地图View
 *@return callout View
 */
- (UIView *)calloutViewForBuilding:(ALDMapView *)mapView;

/**
 *根据anntation生成对应的View
 *@param mapView 地图View
 *@param annotation 指定的标注
 *@return 生成的标注View
 */
- (MKAnnotationView *)mapView:(ALDMapView *)mapView viewForAnnotation:(id <MKAnnotation>)annotation;

/**
 *根据anntation生成对应的Callout View
 *@param mapView 地图View
 *@param annotation 指定的标注
 *@return callout View
 */
- (UIView *)mapView:(ALDMapView *)mapView calloutViewForAnnotation:(id <MKAnnotation>)annotation;

/**
 *当选中一个annotation view时，调用此接口
 *@param mapView 地图View
 *@param views 选中的annotation view
 */
- (void)mapView:(ALDMapView *)mapView didSelectAnnotation:(id <MKAnnotation>)annotation;

/**
 *当选中一个bicycle view时，调用此接口
 *@param mapView 地图View
 *@param views 选中的bicycle view
 */
- (void)mapView:(ALDMapView *)mapView didSelectBicycleAnnotation:(id <MKAnnotation>)annotation;

/**
 *当取消选中的bicycle views时，会回调此接口
 *@param mapView 地图View
 */
- (void)mapViewDidCancelSelectedBicycleAnnotations:(ALDMapView *)mapView;

/**
 *根据overlay生成对应的View
 *@param mapView 地图View
 *@param overlay 指定的overlay
 *@return 生成的覆盖物View
 */
- (MKOverlayView *)mapView:(ALDMapView *)mapView viewForOverlay:(id <MKOverlay>)overlay;

/**
 *设置默认加载矢量道路类型
 *@return 道路类型
 */
- (int)roadTypeForDisplayOnMap;

/**
 *设置默认加载兴趣点类型
 *@return 兴趣点类型
 */
- (int)poiTypeForDisplayOnMap;

/**
 *设置默认使用苹果自带地图数据显示兴趣点
 *@return 开启／关闭
 */
- (BOOL)useApplePoiDataOnMap;

@end
