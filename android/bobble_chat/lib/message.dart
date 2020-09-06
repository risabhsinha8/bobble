import 'package:flutter/material.dart';
//for messages
class Message extends StatelessWidget {
  final String text;
  final double fsize;
  Message(this.text ,this.fsize);//takes text and font size

  @override
  Widget build(BuildContext context) {
    return new Container(
      margin: const EdgeInsets.symmetric(vertical: 10.0),
      child: 
           Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: <Widget>[
              new Text("Me"),
              new Container(
                margin: const EdgeInsets.only(top: 5.0),
                child: new Text(text, style: TextStyle(fontSize: fsize),),
              ),
            ],
          )
        
    );
  }
}