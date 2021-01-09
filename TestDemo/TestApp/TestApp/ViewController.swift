//
//  ViewController.swift
//  TestApp
//
//  Created by 朱猛 on 2020/11/24.
//

import UIKit

class UISubTapGestureRecognizer : UITapGestureRecognizer{
    override var cancelsTouchesInView: Bool{
        get{
            print("getter cancelsTouchesInView : \(super.cancelsTouchesInView)")
            return super.cancelsTouchesInView
        }
        
        set{
            print("setter cancelsTouchesInView : \(newValue)")
            super.cancelsTouchesInView = newValue
        }
    }
    
    override var delaysTouchesBegan: Bool{
        get{
            print("getter delaysTouchesBegan : \(super.delaysTouchesBegan)")
            return super.delaysTouchesBegan
        }
        
        set{
            print("setter delaysTouchesBegan : \(newValue)")
            super.delaysTouchesBegan = newValue
        }
        
    }
    
    override var delaysTouchesEnded: Bool{
        get{
            print("getter delaysTouchesEnded : \(super.delaysTouchesEnded)")
            return super.delaysTouchesEnded
        }
        
        set{
            print("setter delaysTouchesEnded : \(newValue)")
            super.delaysTouchesEnded = newValue
        }
    }
    
}


class UISubPanGestureRecognizer : UIPanGestureRecognizer{
    override var cancelsTouchesInView: Bool{
        get{
            print("getter cancelsTouchesInView : \(super.cancelsTouchesInView)")
            return super.cancelsTouchesInView
        }
        
        set{
            print("setter cancelsTouchesInView : \(newValue)")
            super.cancelsTouchesInView = newValue
        }
    }
    
    override var delaysTouchesBegan: Bool{
        get{
            print("getter delaysTouchesBegan : \(super.delaysTouchesBegan)")
            return super.delaysTouchesBegan
        }
        
        set{
            print("setter delaysTouchesBegan : \(newValue)")
            super.delaysTouchesBegan = newValue
        }
        
    }
    
    override var delaysTouchesEnded: Bool{
        get{
            print("getter delaysTouchesEnded : \(super.delaysTouchesEnded)")
            return super.delaysTouchesEnded
        }
        
        set{
            print("setter delaysTouchesEnded : \(newValue)")
            super.delaysTouchesEnded = newValue
        }
    }
}


class SubView : UIView{
    
    var str  : String?
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        print("\(str!) touchesBegan:")
        super.touchesBegan(touches, with: event)
    }
    
    override func touchesEnded(_ touches: Set<UITouch>, with event: UIEvent?) {
        print("\(str!) touchesEnded:")
        super.touchesEnded(touches, with: event)
    }
    
    override func touchesCancelled(_ touches: Set<UITouch>, with event: UIEvent?) {
        print("\(str!) touchesCancelled:")
        super.touchesCancelled(touches, with: event)
    }
    
    override func touchesMoved(_ touches: Set<UITouch>, with event: UIEvent?) {
        print("\(str!) touchesMoved:")
        super.touchesMoved(touches, with: event)
    }
    
}



class ViewController: UIViewController {
    
    
    @IBOutlet weak var view1: SubView!
    
    
    @IBOutlet weak var view2: SubView!
    
    
    override func viewDidLoad() {
        
        view1.str = "view1"
        view2.str = "view2"
        
        let gestureRecognizer = UISubPanGestureRecognizer.init(target: self, action: #selector(action(gesture:)))
        print("\(gestureRecognizer.cancelsTouchesInView) \(gestureRecognizer.delaysTouchesBegan) \(gestureRecognizer.delaysTouchesEnded)")

        
        view1.addGestureRecognizer(gestureRecognizer)
        
        super.viewDidLoad()
    }
    
    
    @objc func action(gesture: UIGestureRecognizer){
        print("pan")
    }
    
    
    
}




