//
//  ViewController.h
//  SpeakIt!
//
//  Created by Joshua Barrow on 9/23/13.
//  Copyright (c) 2013 Jukaela Enterprises. All rights reserved.
//

@import AVFoundation;

@interface ViewController : UIViewController <AVSpeechSynthesizerDelegate>

@property (strong, nonatomic) IBOutlet UITextView *speechTextView;
@property (strong, nonatomic) IBOutlet UIButton *speakItButton;
@property (strong, nonatomic) IBOutlet UISlider *speedSlider;
@property (strong, nonatomic) IBOutlet UISlider *pitchSlider;

-(IBAction)speakItAction:(id)sender;
-(IBAction)speedAction:(id)sender;
-(IBAction)pitchAction:(id)sender;

@end
