import CustomBtn from "./CustomBtn";

const Post = ({ id, number, title, deletePost }) => {
  return (
    <div style={{ display: "flex", justifyContent: "space-between", alignItems: "center", border: "2px solid black", margin: 5, padding: 10 }}>
      <h4>{number}. {title}</h4>
      <span>{id}</span>
      <CustomBtn onClick={_ => deletePost(id)}>Delete</CustomBtn>
    </div>
  );
}

export default Post;