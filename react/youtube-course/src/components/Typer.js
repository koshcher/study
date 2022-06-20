import { useState } from "react";

const Typer = () => {
  const [str, setStr] = useState('your text');

  function updateStr(e) {
    setStr(e.target.value);
  }

  return (
    <div>
      <h2>{str}</h2>
      <input value={str} onChange={updateStr}></input>
    </div>
  );
}

export default Typer;