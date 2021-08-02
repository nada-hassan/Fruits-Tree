abstract class fruit(var weight: Int) {
  def getweight(): Int = weight
  def getshape(): String
  def getname(): String
}

abstract class OvalShaped( weight:Int) extends fruit(weight:Int) {
  def getshape()="Oval-Shaped"
}
abstract class Tiny( weight:Int) extends fruit(weight:Int) {
  def getshape()="Tiny"
}
abstract class Berry( weight:Int) extends fruit(weight:Int) {
  def getshape()="Berry"
}
abstract class Giant( weight:Int) extends fruit(weight:Int) {
  def getshape()="Giant"
}

class apple(weight:Int) extends OvalShaped(weight:Int) {
  def getname() = "Apple"
}
class pear(weight:Int) extends OvalShaped(weight:Int) {
  def getname() = "Pear"
}
class avocado(weight:Int) extends OvalShaped(weight:Int) {
  def getname() = "Avocado"
}
class papaya(weight:Int) extends OvalShaped(weight:Int) {
  def getname() = "Papaya"
}
class grapes(weight:Int) extends Tiny(weight:Int) {
  def getname() = "Grapes"
}
class cherry(weight:Int) extends Tiny(weight:Int) {
  def getname() = "Cherry"
}
class raspberries(weight:Int) extends Berry(weight:Int) {
  def getname() = "Raspberries"
}
class blueberries(weight:Int) extends Berry(weight:Int) {
  def getname() = "Blueberries"
}
class gooseberries(weight:Int) extends Berry(weight:Int) {
  def getname() = "Gooseberries"
}
class mulberries(weight:Int) extends Berry(weight:Int) {
  def getname() = "Mulberries"
}
class watermelon(weight:Int) extends Giant(weight:Int) {
  def getname() = "Watermelon"
}