import { useState } from "react";
import Counter from "./components/Counter";
import CustomBtn from "./components/CustomBtn";
import PostForm from "./components/PostForm";
import PostInput from "./components/PostInput";
import PostList from "./components/PostList";
import Typer from "./components/Typer";

function App() {
  const [posts, setPosts] = useState([]);

  function deletePost(id) {
    setPosts(posts.filter(post => post.id != id));
  }

  function addPost(newPost) {
    setPosts([...posts, newPost]);
  }


  return (
    <div style={{ display: "flex", flexDirection: "column", justifyContent: "center", margin: 100 }}>
      <PostForm add={addPost} />
      <PostList deletePost={deletePost} posts={posts} />
    </div>
  );
}

export default App;
