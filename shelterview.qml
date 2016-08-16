import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle{


Loader{
    id: animalDetailLoader
}



GridView{



    model: animalModel
    width: 750; height:1334
    id:mainView
    cellWidth:width/4; cellHeight:height/4
    delegate:
        Rectangle{

        Item{

        id:shelter

        MouseArea{
           height:mainView.cellHeight; width:mainView.cellWidth;

            onClicked: {

                var y= mouse.y/mainView.cellWidth
                var xOffset = mouse.x/mainView.cellWidth
                var yOffset = y * 4
                var currIndex = yOffset + xOffset

                // pass in qml object from animal at currentIndex of animalModel
                animalDetailLoader.setSource("animalview.qml");
                animalDetailLoader.object.model = animalModel.data(currIndex, 0x0100 +2)
                mainView.visible=false;


               // animalDetail.model = animalModel.data(2,0x0100 +2 );


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




}





}
}
