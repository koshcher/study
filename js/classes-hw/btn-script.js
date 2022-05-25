class MyButton {
  _text;
  constructor(text, btnClass) {
    this._text = text;
    this.btnClass = btnClass;
  }

  show() {
    document.write(`<button type="button" class="${this.btnClass}">${this._text}</button>`);
  }

  get value() {
    return this._text;
  }

  set value(val) {
    this._text = val;
  }
}

class ColorButton extends MyButton {
  constructor(text, btnClass, colorClass) {
    super(text, btnClass);
    this.colorClass = colorClass;
  }

  show() {
    document.write(`<button type="button" class="${this.btnClass} ${this.colorClass}">${this._text}</button>`);
  }
}

const baseBtn = new MyButton("base btn", "btn");
baseBtn.show();

const redBtn = new ColorButton("red btn", "btn", "btn-red");
redBtn.show();

const greenBtn = new ColorButton("green btn", "btn", "btn-green");
greenBtn.show();