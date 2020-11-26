//
//  ViewController.swift
//  TestApp
//
//  Created by 朱猛 on 2020/11/24.
//

import UIKit

class ViewController: UIViewController {
    
    var tempView : UIView!

    override func viewDidLoad() {
        super.viewDidLoad()
     
        tempView = UIView.init(frame: CGRect(x: 100, y: 100, width: 100, height: 100))
        
        self.view.addSubview(tempView)
        
        tempView.backgroundColor = UIColor.red
        
    }
    
    
    
    @IBAction func onButtonClicked(_ sender: Any) {
        let vc = ViewController1()
        self.present(vc, animated: true, completion: nil)
    }
}


class ViewController1: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        if let sourcevc = self.presentingViewController as? ViewController{
            self.view.addSubview(sourcevc.tempView)
        }
    }
    
    
    
    @IBAction func onButtonClicked(_ sender: Any) {
      
    }
}


