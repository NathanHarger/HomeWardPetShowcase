import QtQuick 2.0
import QtQuick.Controls 1.4




Rectangle{

    GridView{
        width: 1000; height:1000;
        id:grid
       cellWidth:300; cellHeight:300



       // orientation: ListView.Horizontal
        model:animalModel
        delegate: Rectangle
       {

        Image {

                anchors.centerIn:Image.AlignHCenter
                width:grid.cellWidth; height:grid.cellHeight -15

                fillMode: Image.PreserveAspectFit

                source: image

        }
                Text{ y: grid.cellHeight -15
                    text: name }


        }






}



}
