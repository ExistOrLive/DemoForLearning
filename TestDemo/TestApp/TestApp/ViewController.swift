//
//  ViewController.swift
//  TestApp
//
//  Created by 朱猛 on 2020/11/24.
//

import UIKit




class ViewController: UIViewController {
    
    var view2 : UIView!
    var view3 : UIView!

    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.view.backgroundColor = UIColor.white
        
        let str = NSAttributedString(string: "Hello World",
                                     attributes: [NSAttributedString.Key.foregroundColor: UIColor.red,
                                                  NSAttributedString.Key.underlineStyle:NSUnderlineStyle.thick,
                                                  NSAttributedString.Key.underlineColor:UIColor.green])
        
        let view = UILabel(frame: CGRect(x: 50, y: 100, width: 100, height: 100))
        view.numberOfLines = 0
        view.attributedText = str
        self.view.addSubview(view)
        
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
    }
    
    
    @objc func action(gesture: UIGestureRecognizer){
    }
    
    
    
}




