import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle{


    Rectangle{
        id: grid
    anchors.fill:parent
    Grid {
        x: 5; y: 5
        rows: 5; columns: 5; spacing: 10
        focus: true
        Repeater{

            id: model
            model:animalModel
            delegate: appDelegate


        }
    }

    Component
    {
        id: appDelegate

        Item {
            id: item


                width: 200; height: 200


                Image {
                    //y: 20; anchors.horizontalCenter: parent.horizontalCenter
                    source: image
                }
                Text {
                    text: name
                }
            }
        }
}
}
