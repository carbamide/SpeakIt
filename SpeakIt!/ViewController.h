//
//  ViewController.h
//  SpeakIt!
//
//  Created by Joshua Barrow on 9/23/13.
//  Copyright (c) 2013 Jukaela Enterprises. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController
@property (strong, nonatomic) IBOutlet UITextView *speechTextView;
@property (strong, nonatomic) IBOutlet UIButton *speakItButton;
@property (strong, nonatomic) IBOutlet UISegmentedControl *speedSegCont;

-(IBAction)speakItAction:(id)sender;
-(IBAction)speedAction:(id)sender;

@end
