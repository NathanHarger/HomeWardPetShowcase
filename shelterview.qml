import QtQuick 2.0
import QtQuick.Controls 1.4





        Item{

        id:shelter

        MouseArea{
           height:mainView.cellHeight; width:mainView.cellWidth;
            onClicked: {

                mainLoader.source="animalview.qml"
               // animalModel = index;
            }


        }


        Image {

                width:mainView.cellWidth; height:mainView.cellHeight -20

                fillMode: Image.PreserveAspectFit

                source: image

        }
                Text{
                    y: mainView.cellHeight -20
                    text: name }


        }




   // }










