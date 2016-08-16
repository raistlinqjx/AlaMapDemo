//
//  ALDMapView.h
//  ALDMapKit
//
//  Created by dayu on 15/1/8.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import "ALDPointAnnotation.h"
#import "ALDPinAnnotationView.h"
#import "ALDAnnotationView.h"
#import "ALDClusterAnnotationView.h"
#import "ALDAnimatedAnnotationView.h"
#import "ALDPulsingAnnotationView.h"
#import "ALDCalloutAnnotationView.h"
#import "ALDGroundOverlay.h"
#import "ALDCircleView.h"
#import "ALDPolygonView.h"
#import "ALDPolylineView.h"
#import "ALDGroundOverlayView.h"
#import "ALDDownloadObject.h"
#import "ALDRouteObject.h"
#import "ALDPolyline.h"
#import "ALDBusinessSearchManager.h"
#import "ALDMapViewDelegate.h"

@protocol ALDMapViewDelegate;

/**地图背景描画方式
 *BGTYPE_NONE  - 默认
 *BGTYPE_GRID  - 网格
 *BGTYPE_IMAG  - 图片
 */
typedef enum {
    BGTYPE_NONE = 0,    ///<默认
    BGTYPE_GRID,        ///<网格
    BGTYPE_IMAGE        ///<图片
}BGTYPE_ENUM;

/**地图定位缩放按钮显示方式
 *MAPTOOL_DISPLAY_NORMAL   - 默认(3按钮)
 *MAPTOOL_DISPLAY_PAN      - 圆盘(1按钮)
 *MAPTOOL_DISPLAY_SLIDER   - 滑竿(样式一)
 *MAPTOOL_DISPLAY_SLIDER2  - 滑竿(样式二)
 *MAPTOOL_DISPLAY_SLIDER3  - 滑竿(样式三)
 */
typedef enum {
    MAPTOOL_DISPLAY_NORMAL = 0,     ///<默认(3按钮)
    MAPTOOL_DISPLAY_PAN,            ///<圆盘(1按钮)
    MAPTOOL_DISPLAY_SLIDER,         ///<滑竿(样式一)
    MAPTOOL_DISPLAY_SLIDER2,        ///<滑竿(样式二)
    MAPTOOL_DISPLAY_SLIDER3         ///<滑竿(样式三)
}MAPTOOL_DISPLAY_ENUM;

/**地图模式
 *MAP_MODE_NORMAL  - 三维地图
 *MAP_MODE_SIMPLE  - 二维地图
 *MAP_MODE_VECTOR  - 矢量地图
 */
typedef enum {
    MAP_MODE_NORMAL = 0,    ///<三维地图
    MAP_MODE_SIMPLE,        ///<二维地图(仅12～13级地图)
    MAP_MODE_VECTOR         ///<矢量地图
}MAP_MODE_ENUM;

/// 地图接口
@interface ALDMapView : UIView

/// 地图View的Delegate
@property (nonatomic, assign) id<ALDMapViewDelegate> delegate;

/// 当前地图等级,当前可使用的级别为11-18级
@property (nonatomic, retain)NSString *mapLevel;
/// 地图的自定义最小比例尺级别,默认最小11级
@property (nonatomic, assign) NSInteger minMapLevel;
/// 地图的自定义最大比例尺级别,默认最大18级
@property (nonatomic, assign) NSInteger maxMapLevel;
/// 当前地图模式，可设定为三维地图、二维地图、矢量地图
@property (nonatomic) MAP_MODE_ENUM mapMode;

///设定地图View能否支持用户多点缩放(双指)
@property(nonatomic, getter=isZoomEnabled) BOOL zoomEnabled;
///设定地图View能否支持用户缩放(双击)
@property(nonatomic, getter=isZoomEnabledWithTap) BOOL zoomEnabledWithTap;
///设定地图View能否支持长按
@property(nonatomic, getter=isLongPressEnabled) BOOL longPressEnabled;
///设定地图View能否支持用户移动地图
@property(nonatomic, getter=isScrollEnabled) BOOL scrollEnabled;
///设定地图View能否支持旋转
@property(nonatomic, getter=isRotateEnabled) BOOL rotateEnabled;
///设定GPS大头针显示与隐藏
@property(nonatomic, getter=isHideGPS) BOOL hideGPS;
///设定POI图层显示与隐藏
@property(nonatomic, getter=isHidePOI) BOOL hidePOI;
///设定矢量道路图层显示与隐藏
@property(nonatomic, getter=isHidePathVector) BOOL hidePathVector;
///设定道路名称显示与隐藏
@property(nonatomic, getter=isHideRoadName) BOOL hideRoadName;
///设定自行车图层显示与隐藏
@property(nonatomic, getter=isHideBicycle) BOOL hideBicycle;
///设定河流图层显示与隐藏
@property(nonatomic, getter=isHideRiver) BOOL hideRiver;

/// 比例尺的位置，设定坐标以ALDMapView左上角为原点，向右向下增长
@property (nonatomic) CGPoint mapScaleBarPosition;
/// 设定是否显示比例尺
@property (nonatomic, assign) BOOL showMapScaleBar;
/// 缩放按钮(+/-)、滑杆的位置，设定坐标以ALDMapView左上角为原点，向右向下增长
@property (nonatomic) CGPoint zoomBtnPosition;
/// 设定是否显示缩放按钮(+/-)、滑杆
@property(nonatomic, assign) BOOL showZoomBtn;
/// 指南针的位置，设定坐标以ALDMapView左上角为原点，向右向下增长
@property (nonatomic) CGPoint compassPosition;
/// 设定是否显示指南针
@property(nonatomic, assign) BOOL showMapCompass;
/// 代驾列表按钮的位置，设定坐标以ALDMapView左上角为原点，向右向下增长
@property (nonatomic) CGPoint driveBtnPosition;
/// 设定是否显示代驾列表按钮
@property(nonatomic, assign) BOOL showDriveBtn;
/// 定位按钮的位置，设定坐标以ALDMapView左上角为原点，向右向下增长
@property (nonatomic) CGPoint locationPosition;
/// 设定是否显示定位按钮
@property (nonatomic, assign) BOOL showLocationBtn;
/// 定位点图片列表(nil:默认图片,图片个数＝1:静态图片,图片个数>1:动画)
@property (nonatomic, retain) NSArray *locationImages;
/// 定位点图片偏移量，相对屏幕中心向左向上为负，向右向下为正
@property (nonatomic) CGPoint locationImageOffset;
/// 定位跟随模式
@property (nonatomic, assign) BOOL trackingModeFollow;
/// 标注3D转换
@property (nonatomic, assign) BOOL translate3D;

/**
 *初始化地图
 *@param frame 显示窗口大小
 *@param type 地图背景描画方式
 */
- (id)initWithFrame:(CGRect)frame BGType:(BGTYPE_ENUM)type;

/**
 *初始化地图
 *@param frame 显示窗口大小
 *@param type 地图背景描画方式
 *@param display 地图定位缩放按钮显示方式
 */
- (id)initWithFrame:(CGRect)frame BGType:(BGTYPE_ENUM)type MapTool:(MAPTOOL_DISPLAY_ENUM)display;

/**
 *初始化地图
 *@param frame 显示窗口大小
 *@param type 地图背景描画方式
 *@param display 地图定位缩放按钮显示方式
 *@param mode 地图模式
 */
- (id)initWithFrame:(CGRect)frame BGType:(BGTYPE_ENUM)type MapTool:(MAPTOOL_DISPLAY_ENUM)display Mode:(MAP_MODE_ENUM)mode;

/**
 *初始化地图显示(默认)
 */
- (void)initMap;

/**
 *初始化地图显示(指定中心经纬度)
 *@param coordinate 中心经纬度
 */
- (void)initMapWithCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 *初始化地图显示(指定起始瓦块)
 *@param x 起始瓦块X坐标
 *@param y 起始瓦块Y坐标
 */
- (void)initMapWithPos:(NSInteger)x andY:(NSInteger)y;

/**
 *销毁地图释放资源
 */
- (void)destroyMap;

/**
 *放大一级比例尺
 *@return 是否成功
 */
- (BOOL)mapZoomIn;

/**
 *缩小一级比例尺
 *@return 是否成功
 */
- (BOOL)mapZoomOut;

/**
 *获得地图当前可视区域截图
 *@return 返回view范围内的截取的UIImage
 */
- (UIImage *)takeSnapshot;

/**
 *获得地图区域区域截图
 *@return 返回指定区域的截取的UIImage
 */
- (UIImage *)takeSnapshot:(CGRect)rect;

/**
 *获得当前屏幕检索区域
 *@return 返回18级地图基准城市坐标区域
 */
- (ALDAreaSearchBounds)getCurrentScreenBounds;

/**
 *将View矩形区域转换成直角地理坐标矩形区域
 *@param rect View矩形区域(屏幕坐标)
 *@return 返回18级地图基准城市坐标区域
 */
- (ALDAreaSearchBounds)convertRectToMapBounds:(CGRect)rect;

/**
 *将View上任意点转换成地图数据对象
 *@param point View上任意点(屏幕坐标)
 *@return 地图数据对象
 */
- (ALDMapObject *)convertViewPointToMapObject:(CGPoint)point;

@end

///地图View类(和定位、地理编码相关的接口)
@interface ALDMapView (LocationAPI)

/**
 *开始定位
 *异步函数，返回结果在ALDMapViewDelegate的-mapViewDidLocated通知
 *@param animate 是否动画(默认为NO)
 */
- (void)startLocating:(BOOL)animate;

/**
 *设定小人位置气泡显示与隐藏
 *@param showCallout 是否显示气泡
 */
- (void)setShowCallout:(BOOL)showCallout;

/**
 *定位到指定经纬度
 *@param coordinate 地理坐标(经纬度)
 */
- (void)jumpMapToGPSPosition:(CLLocationCoordinate2D)coordinate;

/**
 *滚动到指定经纬度
 *@param coordinate 地理坐标(经纬度)
 */
- (void)scrollMapToGPSPosition:(CLLocationCoordinate2D)coordinate;

@end

///地图View类(和Annotation操作相关的接口)
@interface ALDMapView (AnnotationAPI)

/// 当前地图View的已经添加的标注数组
@property (nonatomic, readonly, retain) NSArray *annotations;

/**
 *向地图窗口添加标注，需要实现ALDMapViewDelegate的-mapView:viewForAnnotation:函数来生成标注对应的View
 *@param annotation 要添加的标注
 */
- (void)addAnnotation:(id <MKAnnotation>)annotation;

/**
 *向地图窗口添加一组标注，需要实现ALDMapViewDelegate的-mapView:viewForAnnotation:函数来生成标注对应的View
 *@param annotations 要添加的标注数组
 */
- (void)addAnnotations:(NSArray *)annotations;

/**
 *向地图窗口添加一组自动聚合的标注，需要实现ALDMapViewDelegate的-mapView:viewForAnnotation:函数来生成标注对应的View
 *@param annotations 要添加的标注数组
 */
- (void)addClusters:(NSArray *)annotations;

/**
 *移除标注
 *@param annotation 要移除的标注
 */
- (void)removeAnnotation:(id <MKAnnotation>)annotation;

/**
 *移除一组标注
 *@param annotation 要移除的标注数组
 */
- (void)removeAnnotations:(NSArray *)annotations;

/**
 *滚动标注到屏幕指定位置
 *@param annotation 选择的标注
 *@param target 屏幕指定位置，设定坐标以ALDMapView左上角为原点，向右向下增长
 */
- (void)scrollAnnotation:(id <MKAnnotation>)annotation ToMapPoint:(CGPoint)target;

/**
 *让指定标注置顶
 *@param annotation 要置顶的标注
 */
- (void)annotationBringToFront:(id <MKAnnotation>)annotation;

/**
 *从起始标注向结束标注动态绘制连接路径
 *@param from   起始标注
 *@param to     结束标注
 *@param anchor 图片的锚点，图片左上角为(0.0f,0.0f),向右向下为正
 *@param offset 弧线的偏移量
 *@param width  线宽
 *@param duration 动画时间
 */
- (void)addPathFromAnnotation:(ALDPointAnnotation *)from
                 toAnnotation:(ALDPointAnnotation *)to
                       anchor:(CGPoint)anchor
                       offset:(CGFloat)offset
                    lineWidth:(CGFloat)width
                     duration:(CGFloat)duration;

/**
 *从标注层删除所有标注连接路径
 */
- (void)removeAllPath;

/**
 *选中当前自行车标注
 *@param annotation 选中的自行车点
 */
- (void)selectBicycle:(id <MKAnnotation>)annotation;

/**
 *取消所有自行车选中状态
 */
- (void)cancelBicycleTouchState;

@end

///地图View类(和Overlay操作相关的接口)
@interface ALDMapView (OverlaysAPI)

/// 当前mapView中已经添加的Overlay数组
@property (nonatomic, readonly, retain) NSArray *overlays;

/**
 *向地图窗口添加Overlay，需要实现ALDMapViewDelegate的-mapView:viewForOverlay:函数来生成标注对应的View
 *@param overlay 要添加的overlay
 */
- (void)addOverlay:(id <MKOverlay>)overlay;

/**
 *向地图窗口添加一组Overlay，需要实现ALDMapViewDelegate的-mapView:viewForOverlay:函数来生成标注对应的View
 *@param overlays 要添加的overlay数组
 */
- (void)addOverlays:(NSArray *)overlays;

/**
 *移除Overlay
 *@param overlay 要移除的overlay
 */
- (void)removeOverlay:(id <MKOverlay>)overlay;

/**
 *移除一组Overlay
 *@param overlays 要移除的overlay数组
 */
- (void)removeOverlays:(NSArray *)overlays;

/**
 *高亮指定建筑轮廓
 *@param object 建筑数据信息
 */
- (void)highlightBuildingWithObject:(ALDBusinessDataObject *)object;

/**
 *清除高亮建筑轮廓
 */
- (void)cancelHighlightBuilding;

/**
 *显示高亮建筑气泡
 */
- (void)showBuildingCalloutView;

@end

///地图View类(和路径相关的接口)
@interface ALDMapView (RouteAPI)

///箭头间距，默认每隔20px画个箭头
extern const NSString *route_arrow_distance_key;
///路径宽度，默认8.0px
extern const NSString *route_line_width_key;
///路径内线宽度，默认6.0px
extern const NSString *route_inside_line_width_key;
///公交路径颜色，默认0x00A8FF
extern const NSString *route_busline_color_key;
///公交路径描边色，默认0x0282C5
extern const NSString *route_busline_bgcolor_key;
///驾车路径颜色，默认0x1AC078
extern const NSString *route_carline_color_key;
///驾车路径描边色，默认0x0E7B4C
extern const NSString *route_carline_bgcolor_key;
///骑行路径颜色，默认0x00A8FF
extern const NSString *route_bicycle_color_key;
///骑行路径描边色，默认0x0282C5
extern const NSString *route_bicycle_bgcolor_key;
///步行路径颜色，默认0x7ECEF4
extern const NSString *route_walkline_color_key;
///轨迹路径颜色，默认0x000000
extern const NSString *route_tracing_color_key;

/**
 *经路属性设置
 *@param routeParam 径路设置
 */
- (void)setupRouteParam:(NSDictionary *)routeParam;

/**
 *经路描画
 *@param routes 导航路径对象数组,成员类型为ALDRouteObject
 */
- (void)addRouteWithArray:(NSArray *)routes;

/**
 *径路自动缩放以适配屏幕
 *@param routes 导航路径对象数组,成员类型为ALDRouteObject
 */
- (void)adjustMapScaleWithPointArray:(NSArray *)routes;

/**
 *获取两个地理位置(经纬度)间的实际直线距离，单位是米
 *@param coorFrom 起点经纬度
 *@param coorTo 终点经纬度
 *@return 实际直线距离，单位是米
 */
- (double)getDistance:(CLLocationCoordinate2D)coorFrom to:(CLLocationCoordinate2D)coorTo;

/**
 *获取两个地理位置(经纬度)间的屏幕直线距离，单位是像素
 *@param coorFrom 起点经纬度
 *@param coorTo 终点经纬度
 *@return 屏幕直线距离，单位是像素
 */
- (double)getPixelDistance:(CLLocationCoordinate2D)coorFrom to:(CLLocationCoordinate2D)coorTo;

@end

///地图View类(和离线下载相关的接口)
@interface ALDMapView (DownloadAPI)

/**
 *更新地图下载状况
 *@param array 已下载完成的瓦块数组
 *@param checkArray 选中准备下载的瓦块数组
 *@param isDelete 是否删除模式
 */
- (void)updateMapDownloadStateWithArray:(NSArray *)array checked:(NSArray *)checkArray delete:(BOOL)isDelete;

/**
 *更新地图显示状态
 *@param option 下载状态数组
 */
- (void)updateMapDownloadState:(NSArray *)option;

/**
 *更新离线地图下载状态
 *@param obj 地图数据对象
 *@param progress 下载进度(百分比)
 */
- (void)updateDownloadState:(ALDMapObject *)obj progress:(NSInteger)progress;

/**
 *下载完成更新显示状态
 *@param obj 地图数据对象
 */
- (void)finishDownload:(ALDMapObject *)obj;

/**
 *删除已经下载的地图
 *@param obj 地图数据对象
 */
- (void)removeDownloaded:(ALDMapObject *)obj;

@end
