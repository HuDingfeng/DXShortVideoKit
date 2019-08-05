//
//  DXVProgressView.m
//  DXShortVideoKitDemo
//
//  Created by huDingfeng on 2019/8/5.
//  Copyright © 2019 hudingfeng. All rights reserved.
//

#import "DXVProgressView.h"
#import "DXVMacro.h"

@implementation DXVProgressView{
    CALayer *currentProgresslayer;
    NSMutableArray  *layerArr;
    CGFloat _minTime;
    CGFloat _maxTime;
}

-(instancetype)initWithFrame:(CGRect)frame minTime:(CGFloat)minTime maxTime:(CGFloat)maxTime{
    if (self = [super initWithFrame:frame]) {
        layerArr = [[NSMutableArray alloc]init];
        _minTime = minTime;
        _maxTime = maxTime;
        [self inital];
    }
    return self;
}

-(void)inital{
    
    self.backgroundColor = [UIColor colorWithRed:50 green:50 blue:50 alpha:0.8];
    CALayer *line = [CALayer layer];
    line.frame =  CGRectMake(self.frame.size.width *(_minTime/_maxTime), 0, 0.5, self.frame.size.height);
    line.backgroundColor = kdxvOrange.CGColor;
    [self.layer addSublayer:line];
    
    currentProgresslayer = [CALayer layer];
    currentProgresslayer.backgroundColor = kdxvGreen.CGColor;
    currentProgresslayer.frame = CGRectMake(0, 0, 0, self.frame.size.height);
    [currentProgresslayer removeAnimationForKey:@"bounds"];
    [self.layer addSublayer:currentProgresslayer];
}

-(void)resetProgress{
    
    currentProgresslayer.frame = CGRectMake(0, 0, 0, self.frame.size.height);
    [layerArr removeAllObjects];
}

-(void)willDeleteLastProgressView{
    if (layerArr.count >0) {
        dispatch_async(dispatch_get_main_queue(), ^{
            [CATransaction begin];
            [CATransaction setDisableActions:YES];
            ((CALayer *)[self->layerArr lastObject]).backgroundColor = kdxvRed.CGColor;
            [CATransaction commit];
        });
    }
}

-(void)cancelDeleteLastProgressView{
    if (layerArr.count >0) {
        dispatch_async(dispatch_get_main_queue(), ^{
            [CATransaction begin];
            [CATransaction setDisableActions:YES];
            ((CALayer *)[self->layerArr lastObject]).backgroundColor = kdxvGreen.CGColor;
            [CATransaction commit];
        });
    }
}


- (void)deleteAllProgressViews{
    
    dispatch_async(dispatch_get_main_queue(), ^{
        for (CALayer *layer in self->layerArr) {
            [layer removeFromSuperlayer];
        }
        [self->layerArr removeAllObjects];
        [CATransaction begin];
        [CATransaction setDisableActions:YES];
        self->currentProgresslayer.frame = CGRectMake(0, 0, 0, self.frame.size.height);
    });
}

-(void)deleteLastProgressView{
    
    [(CALayer *)[layerArr lastObject] removeFromSuperlayer];
    [layerArr removeLastObject];
    [CATransaction begin];
    [CATransaction setDisableActions:YES];
    currentProgresslayer.frame = CGRectMake(((CALayer *)[layerArr lastObject]).frame.origin.x + ((CALayer *)[layerArr lastObject]).frame.size.width, 0, 0, self.frame.size.height);
    [CATransaction commit];
}


-(void)updateProgressWithProgress:(CGFloat)progress{
    [self cancelDeleteLastProgressView];
    dispatch_async(dispatch_get_main_queue(), ^{
        if (!self->currentProgresslayer) {
            CALayer *newlayer = [self generateNewProgressView];
            [self.layer addSublayer:newlayer];
            self->currentProgresslayer = newlayer;
        }
        [CATransaction begin];
        [CATransaction setDisableActions:YES];
        self->currentProgresslayer.frame = CGRectMake(self->currentProgresslayer.frame.origin.x, self->currentProgresslayer.frame.origin.y, self.frame.size.width *progress, self.frame.size.height);
        [CATransaction commit];
    });
}

-(void)pauseProgress{
    if (currentProgresslayer) {
        [layerArr addObject:currentProgresslayer];
        currentProgresslayer = nil;
    }
}

-(CALayer *)generateNewProgressView{
    CALayer *newProgreLayer = [CALayer layer];
    newProgreLayer.frame = CGRectMake(((CALayer *)[layerArr lastObject]).frame.origin.x + ((CALayer *)[layerArr lastObject]).frame.size.width, 0, 0, self.frame.size.height);
    newProgreLayer.backgroundColor = kdxvGreen.CGColor;
    CALayer *line = [CALayer layer];
    line.frame = CGRectMake(0, 0, 0.5, newProgreLayer.frame.size.height);
    line.backgroundColor = kdxvWhite.CGColor;
    [newProgreLayer addSublayer:line];
    return newProgreLayer;
}

@end
