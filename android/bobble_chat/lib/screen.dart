import 'package:flutter/material.dart';
import 'message.dart';

class Screen extends StatefulWidget {
  @override
  _ScreenState createState() => _ScreenState();
}

class _ScreenState extends State<Screen> {
  double size = 12;
  bool increase = true;
  TextEditingController _controller = TextEditingController();
  List<Message> _list = <Message>[];

  //Funtion to add the string in the controller into the list of messages along with fontsize
  void submit(String s) {//takes string in the controller as argument
    _controller.clear();//Empties Text Feild after submission
    Message m = Message(s, size); //Creates message with desired string and size
    size =12.0;//turns to defualt size
    setState(() {
      _list.insert(0, m);//inserts the new message into the list
    });
  }

  @override
  Widget build(BuildContext context) {
    return new Column(children: <Widget>[//main column
      Flexible(//list of all the messages
        child: ListView.builder(
          padding: EdgeInsets.all(8.0),
          reverse: true,
          itemCount: _list.length,
          itemBuilder: (_, int index) => _list[index],
        ),
      ),
      Row(//text feild with button
        children: [
          Flexible(
            child: Container(
                margin: EdgeInsets.all(8.0),
                child: TextField(
                  style: TextStyle(fontSize: size),
                  decoration: InputDecoration(hintText: "Enter a text"),
                  controller: _controller,
                  onSubmitted: submit,
                )),
          ),
          GestureDetector(//to detect long press
              onLongPress: () async {
                increase = true;
                while (increase) {
                  if(size>64)//when size is 64 stop incrementing
                    break;
                  await Future.delayed(Duration(milliseconds: 250));
                  size += 0.3;//increase size till long press ends
                  setState(() {//rerender to show animation 
                    
                  });
                }
              },
              onLongPressUp: () {
                increase = false;//stop increasing size of the text
                setState(() {submit(_controller.text);});//call submit to add into list of messages
              },
              onTap: () => submit(_controller.text),
              child: Padding(
                padding: const EdgeInsets.all(8.0),
                child: Icon(Icons.send),
              ))
        ],
      )
    ]);
  }
}
