import QtQuick 2.0
import QtQuick.Controls 1.4


Rectangle{


    Rectangle{
        id: grid

        Grid {
        anchors.fill:parent

        columns: 3; spacing: 10
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

                width: 250; height: 260

                Image {
            fillMode: Image.PreserveAspectFit
                    source: image
                    width: 250; height: 250
                }
                Text {
                    y: 250;
                    text: name
                }


            }
        }
}
    }

