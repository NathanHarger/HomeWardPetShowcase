import QtQuick 2.0
MouseArea {


GridView {
    focus: true
    delegate: appDelegate
    id :grid
    anchors.fill:parent
    cellWidth: 80; cellHeight: 80;
    model: animalModel

}



Component {
       id: appDelegate

       Item {
           width: 100; height: 100

           Image {
               id:  image
               y: 20; anchors.horizontalCenter: parent.horizontalCenter
               source: image
           }
           Text {
               id: name
               text: name
           }
       }
   }
}
