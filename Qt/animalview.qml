import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle{
TabView{
    anchors.fill:parent
Repeater{
    model: animalModels
Tab{
    title: modelData.Type
    Rectangle {

        GridView {
            focus: true
            delegate: appDelegate
            id :grid
            anchors.fill:parent

            cellWidth: parent.width/2; cellHeight: 200;
            model:modelData
        }
    }
 }
}


Component {
       id: appDelegate

       Item {

           Image {
               id:  image
               height:150
               y: 20; anchors.horizontalCenter: parent.horizontalCenter
               source: image
           }
           Text {
               text: name
           }
       }
   }
}



    ListModel{
        id:animalTypeModel
    }
}