import QtQuick 2.0
Rectangle {
    ListView{
        model: shelterModel
        anchors.fill: parent
        delegate: Rectangle{

            Item{
                anchors.fill: parent
                Text{

                    text: shelterModel[0] + "\n" +
                          shelterModel[1] + "\n" +

                          shelterModel[2] + "\n" +
                          shelterModel[3]

                }

            }




        }
    }
}
