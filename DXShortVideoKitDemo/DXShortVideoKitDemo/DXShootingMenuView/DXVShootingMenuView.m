//
//  DXVShootingMenuView.m
//  DXShortVideoKitDemo
//
//  Created by huDingfeng on 2019/8/5.
//  Copyright © 2019 hudingfeng. All rights reserved.
//

#import "DXVShootingMenuView.h"
#import "Masonry.h"

@implementation DXVShootingMenuView

-(instancetype)initWithFrame:(CGRect)frame{
    if (self = [super initWithFrame:frame]) {
        self.flashBtn = [UIButton buttonWithType:UIButtonTypeCustom];
        [self.flashBtn setImage:[UIImage imageNamed:@""] forState:UIControlStateNormal];
        
        self.shotBtn = [UIButton buttonWithType:UIButtonTypeCustom];
        [self.shotBtn setImage:[UIImage imageNamed:@""] forState:UIControlStateNormal];

        self.beautyBtn = [UIButton buttonWithType:UIButtonTypeCustom];
        [self.beautyBtn setImage:[UIImage imageNamed:@""] forState:UIControlStateNormal];

        self.filterBtn = [UIButton buttonWithType:UIButtonTypeCustom];
        [self.filterBtn setImage:[UIImage imageNamed:@""] forState:UIControlStateNormal];

        self.musicBtn = [UIButton buttonWithType:UIButtonTypeCustom];
        [self.musicBtn setImage:[UIImage imageNamed:@""] forState:UIControlStateNormal];

        NSArray *views =  @[self.flashBtn,
                                self.shotBtn,
                                self.beautyBtn,
                                self.filterBtn,
                                self.musicBtn];
        [views mas_distributeViewsAlongAxis:MASAxisTypeVertical withFixedSpacing:15 leadSpacing:15 tailSpacing:0.f];
    }
    return self;
}

@end
