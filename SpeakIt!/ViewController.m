//
//  ViewController.m
//  SpeakIt!
//
//  Created by Joshua Barrow on 9/23/13.
//  Copyright (c) 2013 Jukaela Enterprises. All rights reserved.
//

@import AVFoundation;

#import "ViewController.h"

@interface ViewController ()
@property (nonatomic) float speechSpeed;
@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	
    [self setSpeechSpeed:AVSpeechUtteranceDefaultSpeechRate];
    [[self speedSegCont] setSelectedSegmentIndex:1];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

-(IBAction)speakItAction:(id)sender
{
    AVSpeechSynthesizer *synthesizer = [[AVSpeechSynthesizer alloc] init];
    
    AVSpeechUtterance *utterance = [AVSpeechUtterance speechUtteranceWithString:[[self speechTextView] text]];
    [utterance setRate:_speechSpeed];

    [synthesizer speakUtterance:utterance];
}

-(IBAction)speedAction:(id)sender
{
    UISegmentedControl *segmentedControl = sender;
    
    if ([segmentedControl selectedSegmentIndex] == 0) {
        [self setSpeechSpeed:AVSpeechUtteranceMinimumSpeechRate];
    }
    else if ([segmentedControl selectedSegmentIndex] == 1) {
        [self setSpeechSpeed:AVSpeechUtteranceDefaultSpeechRate];
    }
    else {
        [self setSpeechSpeed:AVSpeechUtteranceMaximumSpeechRate];
    }
}
@end
