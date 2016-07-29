import QtQuick 2.0

Item {

       id: appDelegate


           width: 200; height: 200

            Image {
                //y: 20; anchors.horizontalCenter: parent.horizontalCenter
                source: image
            }
            Text {
                text: name
            }
    }



