import java.util.Stack
case class Node(var v: fruit,var left: Node,var right: Node)
class BST {

  var root: Node =null

  def insert(key: fruit): Unit = {
    val node: Node = Node(key,null,null)
    if (root == null) {
      root = node
      return
    }
    var prev: Node = null
    var temp: Node = root
    while (temp != null) if (temp.v.weight > key.weight) {
      prev = temp
      temp = temp.left
    } else if (temp.v.weight < key.weight) {
      prev = temp
      temp = temp.right
    }
    if (prev.v.weight > key.weight) prev.left = node else prev.right = node
  }

  def inorder(f:fruit=>Unit): Unit = {
    var temp: Node = root
    val stack: Stack[Node] = new Stack[Node]()
    while (temp != null || !stack.isEmpty) if (temp != null) {
      stack.add(temp)
      temp = temp.left
    } else {
      temp = stack.pop()
      f(temp.v)
      temp = temp.right
    }
  }

  def Iterate(): Unit ={
    def print_tree(node:fruit): Unit ={
      printNode(node)
    }
    inorder(print_tree)
  }
  def filterByWeight(weight:Int): Unit ={
    var flag=false
    def filter(node:fruit): Unit ={
      if(matchWeight(node,weight)){
        printNode(node)
        flag=true
      }
    }
    inorder(filter)
    if(!flag){
      print("No fruits found")
    }  }
  def matchWeight(x: fruit,w:Int): Boolean= (x,w) match {
    case (x,w) if x.getweight() > w => true
    case _ => false
  }
  def filterByType(filterType: String): Unit ={
    var flag=false
    def filter(node:fruit): Unit ={
      if(matchType(node,filterType)){
        printNode(node)
        flag=true
      }
    }
    inorder(filter)
    if(!flag){
      print("No fruits of that type found")
    }
  }
  def matchType(x: fruit,t:String): Boolean= (x,t) match {
    case (x,t) if x.getname()==t => true
    case _ => false
  }
  def magnifyByType(Type:String, Weight:Int): Unit ={
    val n=new BST();
    def magnify(node:fruit): Unit ={
      if(matchType(node,Type)){
        node.weight += Weight
      }
      n.insert(node)
    }

    inorder(magnify)
    val newNode:Node=n.root
    root=newNode
  }


  def findHeaviest(): Node = {
    var node: Node = root
    while(node.right != null){
      node=node.right
    }
    node
  }
  def findLightest(): Node = {
    var node: Node = root
    while(node.left != null){
      node=node.left
    }
    node
  }
  def printNode(node:fruit): Unit ={
    println(s"{fruit type: ${node.getname()}, fruit shape: ${node.getshape()}, fruit weight: ${node.getweight()}}")
  }
}
