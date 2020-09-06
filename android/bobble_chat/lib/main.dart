import 'package:flutter/material.dart';
import 'screen.dart';

void main()=> runApp(MyApp());

class MyApp extends StatelessWidget { 
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: "Bobble Chat",
      home: Scaffold(
        appBar: AppBar(title: Text("Bobble Chat"),),
        body: Screen(),
      )
    );
  }
}