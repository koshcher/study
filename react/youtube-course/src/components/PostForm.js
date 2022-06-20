import { useState } from "react";
import CustomBtn from "./CustomBtn";
import PostInput from "./PostInput";

const PostForm = ({ add }) => {
  const [newPost, setNewPost] = useState({ id: Date.now(), number: 1, title: "" });

  function addNewPost(e) {
    e.preventDefault();
    add(newPost);
    setNewPost({ id: Date.now(), number: newPost.number + 1, title: "" });
  }

  return (
    <form style={{ display: "flex", justifyContent: "center" }}>
      <PostInput
        value={newPost.title}
        type="text"
        placeholder="title"
        onChange={e => setNewPost({ ...newPost, title: e.target.value })}
      />
      <CustomBtn onClick={addNewPost}>Add</CustomBtn>
    </form>
  );
}

export default PostForm;