//
//  AlaMapNaviViewController.h
//  AlaMapDemo
//
//  Created by Qian JX on 16/8/22.
//  Copyright © 2016年 zfsoft. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ALDMapKit/ALDMapKit.h>
@interface AlaMapNaviViewController : UIViewController<UISearchBarDelegate, UISearchResultsUpdating, ALDMapViewDelegate>
@property (nonatomic, retain) UISearchController *search;
@property (nonatomic, retain) UISearchBar *searchBar;
@property (nonatomic, retain) ALDMapView *mapView;
@end

