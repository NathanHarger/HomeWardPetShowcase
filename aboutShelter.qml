import QtQuick 2.0
Rectangle {
    ListView{
        model: shelterModel
        anchors.fill: parent
        delegate: Rectangle{

            Item{
                Text{
                    text:  address

                }
            }

        }
    }
}
