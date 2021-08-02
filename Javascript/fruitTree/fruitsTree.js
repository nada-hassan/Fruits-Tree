function Fruit(){}
Fruit.prototype={
   weight:0,
   left:null,
   right:null,
   getWeight: function(){return this.weight; },
   setWeight: function(weight) {this.weight=weight;},
   getType: function(){return this.type; },
   getShape: function(){return this.shape; },
   getLeft: function(){return this.left; },
   setLeft: function(weight) {this.left=weight;},
   getRight: function(){return this.right; },
   setRight: function(weight) {this.right=weight;}

};

function tiny(){}
tiny.prototype ={
    __proto__: Fruit.prototype,
    getShape: function(){return "tiny" ;},
}
function oval(){}
oval.prototype ={
    __proto__: Fruit.prototype,
    getShape: function(){return "oval" ;},
}
function berry(){}
berry.prototype ={
    __proto__: Fruit.prototype,
    getShape: function(){return "berry" ;},
}
function giant(){}
giant.prototype ={
    __proto__: Fruit.prototype,
    getShape: function(){return "giant" ;},
}

function apple(){}
apple.prototype ={
    __proto__: oval.prototype,
    getType: function(){return "apple" ;},
}
function pear(){}
pear.prototype ={
    __proto__: oval.prototype,
    getType: function(){return "pear" ;},
}

function avocado(){}
avocado.prototype ={
    __proto__: oval.prototype,
    getType: function(){return "avocado" ;},
}

function papaya(){}
papaya.prototype ={
    __proto__: oval.prototype,
    getType: function(){return "papaya" ;},
}
function cherry(){}
cherry.prototype ={
    __proto__: tiny.prototype,
    getType: function(){return "cherry" ;}
}
function grapes(){}
grapes.prototype ={
    __proto__: tiny.prototype,
    getType: function(){return "grapes" ;}
}


function blueberries(){}
blueberries.prototype ={
    __proto__: berry.prototype,
    getType: function(){return "blueberries" ;}
}

function gooseberries(){}
gooseberries.prototype ={
    __proto__: berry.prototype,
    getType: function(){return "gooseberries" ;}
}

function mulberries(){}
mulberries.prototype ={
    __proto__: berry.prototype,
    getType: function(){return "mulberries" ;}
}

function raspberries(){}
raspberries.prototype ={
    __proto__: berry.prototype,
    getType: function(){return "raspberries" ;}
}

function watermelon(){}
watermelon.prototype ={
    __proto__: giant.prototype,
    getType: function(){return "watermelon" ;}
}


/////////////////tree////////////////


function Tree(){
     this.root=null;
     this.magnifiedfruits=[];
     

}
Tree.insert= function (fruit){
    if(this.root == null)
         this.root=fruit;
        
    else
        insertFruit(this.root,fruit);  
    
    }


Tree.Iterate= function (){  
    Inorder(this.root,traverse)
}

Tree.FilterByType= function (Type){
    Inorder(this.root,Typefilter,Type)
}


Tree.FilterByweight= function (Weight){ 
    Inorder(this.root,Weightfilter,Weight)
}


Tree.magnifyByType=function(Type,Weight){
    this.magnifiedfruits=[];
    Inorder(this.root,magnify,Type,Weight,this.magnifiedfruits,this.num)  
    this.root=null;
    for(var i=0;i<this.magnifiedfruits.length;i++){
            this.magnifiedfruits[i].left=null;
            this.magnifiedfruits[i].right=null; 
            this.insert(this.magnifiedfruits[i]);
            
        }  

} 


Tree.findHeaviest=function(){
    var root=this.root;
    if(root==null)
        return;
   
    while(root.right!= null){
        root=root.right;
    }
    console.log("Heaviest Node :{Fruit type: "+root.getType()+" ,fruit shape: "+root.getShape()+" ,fruit weight: "+root.getWeight());
    

}

Tree.findLightest=function(){
    var root=this.root;
    if(root==null)
        return;
   
    while(root.left!= null){
        root=root.left;
    }
    console.log("lightest Node :{Fruit type: "+root.getType()+" ,fruit shape: "+root.getShape()+" ,fruit weight: "+root.getWeight());
    

}

var lightest=function(root){
    
        if (root == null) 
         { return 2147483647;}
 
        var res = root;
        var lres = findMin(node.left);
        var rres = findMin(node.right);
 
        if (lres < res.weight) res.weight = lres;
        if (rres < res.weight) res.weight = rres;
        return res;
      
}

var magnify=function(root,Type,Weight){
   
    if(root.getType()==Type||root.getShape()==Type){
        root.setWeight(root.getWeight()+Weight);
        return true; 
       }
       return true;
    }  

   
var Inorder= function (root,fun,filter,magnify,nodes){
    if(root==null||root==undefined){
        return;
    }
    Inorder(root.left,fun,filter,magnify,nodes);
    
    if(fun(root,filter,magnify)){
        nodes.push(root);    
    }

    Inorder(root.right,fun,filter,magnify,nodes);
}


var insertFruit= function (root,fruit){
    if(root==null){
        return fruit;
    
    }
   if(root.getWeight()<fruit.getWeight()){
        root.setRight(insertFruit(root.getRight(),fruit));
  
   }
    else{
        root.setLeft(insertFruit(root.getLeft(),fruit));
      }
    return root;
}

var traverse=function(root){
    console.log("{Fruit type: "+root.getType()+" ,fruit shape: "+root.getShape()+" ,fruit weight: "+root.getWeight());
} 


var Typefilter=function(root,Type){
   if(root.getType()==Type || root.getShape()==Type)
    console.log("{Fruit type: "+root.getType()+" ,fruit shape: "+root.getShape()+" ,fruit weight: "+root.getWeight());
} 



var Weightfilter=function(root,Weight){
   
    if(root.getWeight()>Weight)
    console.log("{Fruit type: "+root.getType()+" ,fruit shape: "+root.getShape()+" ,fruit weight: "+root.getWeight());
} 





///////////test///////////////




var b=Object.create(Tree);
var apple1=Object.create(apple.prototype);
apple1.setWeight(30);
var grapes1=Object.create(grapes.prototype);
grapes1.setWeight(50);
var papaya1=Object.create(papaya.prototype);
papaya1.setWeight(15);
var cherry1=Object.create(cherry.prototype);
cherry1.setWeight(20);
var grapes2=Object.create(grapes.prototype);
grapes2.setWeight(10);
var gooseberries1=Object.create(gooseberries.prototype);
gooseberries1.setWeight(40);
var mulberries1=Object.create(mulberries.prototype);
mulberries1.setWeight(60);
var cherry2=Object.create(cherry.prototype);
cherry2.setWeight(35);
var watermelon1=Object.create(watermelon.prototype);
watermelon1.setWeight(90);
var raspberries1=Object.create(raspberries.prototype);
raspberries1.setWeight(25);
var apple2=Object.create(apple.prototype);
apple2.setWeight(75);
var pear1=Object.create(pear.prototype);
pear1.setWeight(65);
var blueberries1=Object.create(blueberries.prototype);
blueberries1.setWeight(45);
var avocado1=Object.create(avocado.prototype);
avocado1.setWeight(80);




////inserting fruits////
b.insert(apple1);
b.insert(grapes1);
b.insert(papaya1);
b.insert(cherry1);
b.insert(grapes2);
b.insert(gooseberries1);
b.insert(mulberries1);
b.insert(cherry2);
b.insert(watermelon1);
b.insert(raspberries1);
b.insert(apple2);
b.insert(pear1);
b.insert(blueberries1);
b.insert(avocado1);



console.log("-------- Test iterate --------")
b.Iterate()
console.log("------------------------------------")
console.log("-------- test filter by type (Apple) --------")
b.FilterByType("apple")
console.log("------------------------------------")
console.log("-------- test filter by weight (40) --------")
b.FilterByweight(40)
console.log("------------------------------------")
console.log("-------- test find heaviest --------")
b.findHeaviest()
console.log("------------------------------------")
console.log("-------- test find lightest --------")
b.findLightest()
console.log("------------------------------------")
console.log("-------- Test magnify(Grapes,7) --------")
b.magnifyByType("grapes",7)
b.Iterate()
console.log("------------------------------------")





