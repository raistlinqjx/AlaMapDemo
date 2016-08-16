//
//  ViewController.m
//  AlaMapDemo
//
//  Created by Qian JX on 16/8/16.
//  Copyright © 2016年 zfsoft. All rights reserved.
//

#import "ViewController.h"
#import "AlaMapViewController.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)mapBtnPressed:(id)sender{
    AlaMapViewController *controller = [[AlaMapViewController alloc] init];
    [self.navigationController pushViewController:controller animated:YES];
}

@end
